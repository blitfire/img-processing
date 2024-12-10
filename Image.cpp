//
// Created by george on 08/12/24.
//
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include "stb-headers.h"
#include "Pixel.h"
#include "Image.h"

Image::Image(std::string_view path, const int req_channels) : channels{req_channels} {
    // Set required channels to 0 as default, will likely change later on
    unsigned char *img_bytes {stbi_load(path.data(), &width, &height, &file_channels, req_channels)};

    // At the moment this just exits, but I want to use exceptions
    if (img_bytes == nullptr) {
        throw std::ios_base::failure("Image \""+std::string(path)+"\" could not be opened.");
    }

    size = width * height * req_channels;
    // Potentially expensive copy, but for the std::vector features its probably worth it
    bytes = {img_bytes, img_bytes+size};
    stbi_image_free(img_bytes);
}

Pixel Image::getPixel(const long x, const long y) {
    if (x < 0 || x >= width ||
        y < 0 || y >= height) {
        throw std::out_of_range("Image: Pixel index ["+std::to_string(x)+", "+std::to_string(y)+"] out of range.");
    }

    const auto pixel_i {bytes.begin() + channels * (width * y + x)};
    return Pixel({pixel_i, pixel_i+channels});
}
