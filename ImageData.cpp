//
// Created by george on 08/12/24.
//
#include <iostream>
#include <stdexcept>
#include <string>
#include "stb-headers.h"
#include "Pixel.h"
#include "ImageData.h"

ImageData::ImageData(const std::string_view path, const int req_channels) : channels{req_channels} {
    int file_channels;
    // Set required channels to 0 as default, will likely change later on
    unsigned char *img_bytes {stbi_load(path.data(), &width, &height, &file_channels, channels)};

    // At the moment this just exits, but I want to use exceptions
    if (img_bytes == nullptr)
        throw std::ios_base::failure("ImageData \""+std::string(path)+"\" could not be opened.");

    if (file_channels != channels)
        throw std::runtime_error("File format does not match required format.");

    // May require further optimisation
    for (int i {}; i < height; i++) {
        pixels.emplace_back(width);
        const int rowIndex = i * width;
        for (int j {}; j < width; j++) {
            pixels.back()[j] = {img_bytes+(rowIndex+j)*channels, channels};
        }
    }
    stbi_image_free(img_bytes);
}

Pixel& ImageData::getPixel(const int x, const int y) {
    return pixels[y][x];
}
