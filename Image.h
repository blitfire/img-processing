//
// Created by george on 08/12/24.
//

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>

class Image {
protected:
    std::vector<unsigned char> data;
    int width {}, height {}, file_channels {}, channels {};

    size_t size; // Size of image loaded, not necessarily the same as the image file

    Image(const char *path, int req_channels);

public:
    virtual void save(const char *path) const = 0;

    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] int getChannels() const { return channels; }

    virtual ~Image() = default;
};



#endif //IMAGE_H
