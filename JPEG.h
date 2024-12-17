//
// Created by george on 09/12/24.
//

#ifndef JPEG_H
#define JPEG_H

#include <string_view>
#include <optional>
#include <vector>
#include "PixelRef.h"
#define JPEG_CHANNELS 3

class JPEG {
    std::vector<float> data;
    int width {}, height {};
    int compression_quality {100};

public:
    explicit JPEG(std::string_view path);

    void save(std::string_view path) const;

    // Using optional because sometimes it's OK if there is no pixel
    [[nodiscard]] std::optional<PixelRef> getPixel(long x, long y);
    [[nodiscard]] int getWidth() const { return width; }
    [[nodiscard]] int getHeight() const { return height; }

    void setCompressionQuality(const int quality) { compression_quality = quality; }
};



#endif //JPEG_H
