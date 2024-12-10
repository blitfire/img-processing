//
// Created by george on 09/12/24.
//

#ifndef PIXEL_H
#define PIXEL_H

#include <span>
#include <optional>

// This class is here to provide a controlled interface with an individual pixel of a larger image in a simple manner
class Pixel {
    std::span<unsigned char> bytes;
public:
    explicit Pixel(const std::span<unsigned char> p_bytes) : bytes{p_bytes} {}
    Pixel() = default;
    unsigned char& operator[](size_t index);
};



#endif //PIXEL_H
