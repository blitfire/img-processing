//
// Created by george on 09/12/24.
//

#ifndef JPEG_H
#define JPEG_H

#include <string_view>
#include <vector>
#include "Pixel.h"

class JPEG {
    std::vector<std::vector<Pixel>> pixels;
    int width {}, height {};
    static constexpr int channels {3};
    int compressionQuality {100};

    [[nodiscard]] std::vector<unsigned char> getBytes() const;

public:
    explicit JPEG(std::string_view path);
    void write(std::string_view path) const;

    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }
    [[nodiscard]] Pixel& getPixel(const int x, const int y) { return pixels[y][x]; }

    JPEG& setCompressionQuality(const int quality) { compressionQuality = quality; return *this; }
};



#endif //JPEG_H
