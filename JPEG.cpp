//
// Created by george on 09/12/24.
//

#include <string>
#include <stdexcept>
#include <ios>
#include "image-data-utils.h"
#include "stb-headers.h"
#include "JPEG.h"

JPEG::JPEG(std::string_view path) {
    // Set required channels to 0 as default, will likely change later on
    int channels;
    unsigned char *img_bytes {stbi_load(path.data(), &width, &height, &channels, JPEG_CHANNELS)};

    if (img_bytes == nullptr)
        throw std::ios_base::failure("ImageData \""+std::string(path)+"\" could not be opened.");

    if (channels != JPEG_CHANNELS)
        throw std::runtime_error("Image is not in the required format.");

    // Potentially expensive copy, but for the std::vector features its probably worth it.
    // We normalise the channel values into the range 0.0 to 1.0 for easier manipulation
    const int size = width * height * JPEG_CHANNELS;
    for (int i {}; i < size; i++) {
        data.push_back(normaliseChannel(img_bytes[i]));
    }
    stbi_image_free(img_bytes);
}

std::optional<PixelRef> JPEG::getPixel(long x, long y) {
    if (x < 0 || x >= width ||
        y < 0 || y >= height) {
        return std::nullopt;
        }

    const auto pixel_i {data.begin() + JPEG_CHANNELS * (width * y + x)};
    return PixelRef({pixel_i, pixel_i + JPEG_CHANNELS});
}

void JPEG::save(std::string_view path) const {
    stbi_write_jpg(path.data(),
        width,
        height,
        JPEG_CHANNELS,
        data.data(),
        compression_quality);
}
