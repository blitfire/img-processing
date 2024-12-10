//
// Created by george on 09/12/24.
//
#include <stdexcept>
#include <iostream>
#include "Pixel.h"

unsigned char& Pixel::operator[](const size_t index) {
    if (index >= bytes.size())
        throw std::out_of_range("Pixel: Channel Index ["+std::to_string(index)+"] is out of range [0.."+std::to_string(bytes.size()-1)+")");

    return bytes[index];
}
