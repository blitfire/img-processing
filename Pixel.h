//
// Created by george on 17/12/24.
//

#ifndef PIXEL_H
#define PIXEL_H

#include <vector>

class Pixel {
    std::vector<float> data;
    static constexpr float maxChar {255.0f};

public:
    explicit Pixel(unsigned char numChannels);
    Pixel(const unsigned char* channels, int numChannels);
    Pixel() = default;

    [[nodiscard]] std::vector<unsigned char> getBytes() const;

    float& operator[](size_t channel_i);
};



#endif //PIXEL_H
