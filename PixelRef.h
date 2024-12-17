//
// Created by george on 09/12/24.
//

#ifndef PIXEL_H
#define PIXEL_H

#include <span>

// Acts as a reference to a pixel in an image
class PixelRef {
    std::span<float> bytes;
public:
    explicit PixelRef(const std::span<float>& p_bytes) : bytes{p_bytes} {}
    PixelRef() = default;
    float& operator[](size_t index);
};



#endif //PIXEL_H
