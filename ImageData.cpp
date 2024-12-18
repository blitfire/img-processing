//
// Created by george on 08/12/24.
//
#include <iostream>
#include <stdexcept>
#include <string>
#include "stb-headers.h"
#include "Pixel.h"
#include "ImageData.h"
#include "PNG.h"

template <typename Format>
ImageData<Format>::ImageData(const std::string_view path) {
    unsigned char *img_bytes {stbi_load(path.data(), &width, &height, &channels, 0)};

    if (img_bytes == nullptr)
        throw std::ios_base::failure("ImageData \""+std::string(path)+"\" could not be opened.");

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

template <typename Format>
std::vector<unsigned char> ImageData<Format>::getBytes() const {
    std::vector<unsigned char> bytes;
    for (int i {}; i < height; i++) {
        for (int j {}; j < width; j++) {
            std::vector pixelBytes {pixels[i][j].getBytes()};
            bytes.insert(bytes.end(), pixelBytes.begin(), pixelBytes.end());
        }
    }
    return bytes;
}
