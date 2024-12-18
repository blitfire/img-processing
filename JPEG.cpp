//
// Created by george on 09/12/24.
//

#include <ios>
#include "stb-headers.h"
#include "JPEG.h"

JPEG::JPEG(std::string_view path) {
    int fileChannels;
    unsigned char *img_bytes {stbi_load(path.data(), &width, &height, &fileChannels, channels)};

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
std::vector<unsigned char> JPEG::getBytes() const {
    std::vector<unsigned char> bytes;
    for (int i {}; i < height; i++) {
        for (int j {}; j < width; j++) {
            std::vector pixelBytes {pixels[i][j].getBytes()};
            bytes.insert(bytes.end(), pixelBytes.begin(), pixelBytes.end());
        }
    }
    return bytes;
}

void JPEG::write(std::string_view path) const {
    stbi_write_jpg(path.data(), width, height, channels, getBytes().data(), compressionQuality);
}
