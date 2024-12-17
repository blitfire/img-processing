//
// Created by george on 08/12/24.
//

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string_view>
#include "Pixel.h"

// Virtual class to allow simplified interaction with image files and data
// As it stands, this class is implemented with 8-bit-per-channel images in mind
class ImageData {
    std::vector<std::vector<Pixel>> pixels;
    int width {}, height {};
    int channels {};

protected:
    ImageData(std::string_view path, int req_channels);

public:
    virtual void save(const char *path) const = 0;

    // Using optional because sometimes it's OK if there is no pixel
    [[nodiscard]] Pixel& getPixel(int x, int y);
    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] int getChannels() const { return channels; }

    virtual ~ImageData() = default;
};



#endif //IMAGE_H
