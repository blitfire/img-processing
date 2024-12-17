//
// Created by george on 17/12/24.
//

#ifndef PIXEL_H
#define PIXEL_H

#include <vector>

class Pixel {
    std::vector<float> data;

public:
    explicit Pixel(unsigned char numChannels);
    Pixel(const unsigned char* channels, int numChannels);
    Pixel() = default;

    float& operator[](size_t channel_i);
};



#endif //PIXEL_H
