//
// Created by george on 08/12/24.
//
#include <iostream>
#include <cstdlib>
#include "stb-headers.h"
#include "Image.h"

Image::Image(const char *path, const int req_channels) : channels{req_channels} {
    // Set required channels to 0 as default, will likely change later on
    unsigned char *img_bytes {stbi_load(path, &width, &height, &file_channels, req_channels)};

    // At the moment this just exits, but I want to use exceptions
    if (img_bytes == nullptr) {
        std::cerr << "Image " << path << " could not be loaded." << std::endl;
        std::exit(1);
    }

    size = width * height * req_channels;
    // Potentially expensive copy, but for the std::vector features its probably worth it
    bytes = {img_bytes, img_bytes+size};
    stbi_image_free(img_bytes);
}

std::span<const unsigned char> Image::getPixel(const long x, const long y) {
    const auto pixel_i {bytes.begin() + channels * (width * y + x)};
    return {pixel_i, pixel_i+channels};
}
