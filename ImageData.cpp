//
// Created by george on 08/12/24.
//
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include "stb-headers.h"
#include "PixelRef.h"
#include "ImageData.h"

ImageData::ImageData(const std::string_view path, const int req_channels) : channels{req_channels} {
    // Set required channels to 0 as default, will likely change later on
    unsigned char *img_bytes {stbi_load(path.data(), &width, &height, &file_channels, req_channels)};

    // At the moment this just exits, but I want to use exceptions
    if (img_bytes == nullptr) {
        throw std::ios_base::failure("ImageData \""+std::string(path)+"\" could not be opened.");
    }

    size = width * height * req_channels;
    // Potentially expensive copy, but for the std::vector features its probably worth it
    bytes = {img_bytes, img_bytes+size};
    stbi_image_free(img_bytes);
}

std::optional<PixelRef> ImageData::getPixel(const long x, const long y) {
    if (x < 0 || x >= width ||
        y < 0 || y >= height) {
        return std::nullopt;
    }

    const auto pixel_i {bytes.begin() + channels * (width * y + x)};
    return PixelRef({pixel_i, pixel_i + channels});
}
