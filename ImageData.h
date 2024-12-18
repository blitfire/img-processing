//
// Created by george on 08/12/24.
//

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string_view>
#include "Pixel.h"

// Abstract class to allow simplified interaction with image files and data
// As it stands, this class is implemented with 8-bit-per-channel images in mind

template <typename Format>
class ImageData {
    std::vector<std::vector<Pixel>> pixels;
    int width {}, height {};
    int channels {};

protected:
    explicit ImageData(std::string_view path);
    [[nodiscard]] std::vector<unsigned char> getBytes() const;

public:
    virtual void write(std::string_view path) const = 0;

    [[nodiscard]] Pixel& getPixel(const int x, const int y) { return pixels[y][x]; }
    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] int getChannels() const { return channels; }

    virtual ~ImageData() = default;
};

#endif //IMAGE_H
