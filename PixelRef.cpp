//
// Created by george on 09/12/24.
//
#include <stdexcept>
#include <iostream>
#include "PixelRef.h"

float& PixelRef::operator[](const size_t index) {
    /* Using an invalid pixel index returns an optional value because a whole pixel can be ignored, but channels are an
     * inherent property of the image. Accessing a channel incorrectly is definitely a problem, accessing a pixel
     * incorrectly might not be.
     */
    if (index >= bytes.size())
        throw std::out_of_range("PixelRef: Channel Index ["+std::to_string(index)+"] is out of range [0.."+std::to_string(bytes.size()-1)+")");

    return bytes[index];
}
