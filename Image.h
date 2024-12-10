//
// Created by george on 08/12/24.
//

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string_view>
#include <optional>
#include "Pixel.h"

class Image {
    std::vector<unsigned char> bytes;
    int width {}, height {};
    int file_channels {}, channels {};

    size_t size; // Size of image loaded, not necessarily the same as the image file

protected:
    Image(std::string_view path, int req_channels);
    [[nodiscard]] const std::vector<unsigned char>& getBytes() const { return bytes; }
    virtual void save(const char *path) const = 0;

public:
    // Using optional because sometimes it's OK if there is no pixel
    [[nodiscard]] std::optional<Pixel> getPixel(long x, long y);
    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] int getChannels() const { return channels; }

    virtual ~Image() = default;
};



#endif //IMAGE_H
