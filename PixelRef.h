//
// Created by george on 09/12/24.
//

#ifndef PIXEL_H
#define PIXEL_H

#include <span>
#include <optional>

// Acts as a reference to a pixel in an image
class PixelRef {
    std::span<unsigned char> bytes;
public:
    explicit PixelRef(const std::span<unsigned char>& p_bytes) : bytes{p_bytes} {}
    PixelRef() = default;
    unsigned char& operator[](size_t index);
};



#endif //PIXEL_H
