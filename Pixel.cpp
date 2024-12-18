//
// Created by george on 17/12/24.
//

#include "Pixel.h"
#include <cmath>
#include <bits/ranges_algo.h>

Pixel::Pixel(const unsigned char numChannels) : data(numChannels, 0.0f) {}

Pixel::Pixel(const unsigned char *channels, const int numChannels) : Pixel(numChannels) {
    // Need to normalise the channels
    for (int i {}; i < numChannels; i++) {
        data[i] = static_cast<float>(channels[i]) / maxChar;
    }
}

std::vector<unsigned char> Pixel::getBytes() const {
    std::vector<unsigned char> bytes;
    for (int i {}; i < data.size(); i++) {
        const float byteVal {std::round(data[i] * maxChar)};
        bytes.push_back(static_cast<unsigned char>(byteVal));
    }

    return bytes;
}

float& Pixel::operator[](const size_t channel_i) {
    return data[channel_i];
}
