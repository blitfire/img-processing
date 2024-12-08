//
// Created by george on 08/12/24.
//

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>

class Image {
    std::vector<unsigned char> data;
    int width {}, height {}, channels {};

    size_t size;

public:
    explicit Image(const char *path);

    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] int getChannels() const { return channels; }

    // ~Image();
};



#endif //IMAGE_H
