//
// Created by george on 17/12/24.
//

#include "Pixel.h"

Pixel::Pixel(const unsigned char numChannels) : data(numChannels, 0.0f) {}

Pixel::Pixel(const unsigned char *channels, const int numChannels) : Pixel(numChannels) {
    // Need to normalise the channels
    for (int i {}; i < numChannels; i++) {
        data[i] = static_cast<float>(channels[i]) / 255.0f;
    }
}

float& Pixel::operator[](const size_t channel_i) {
    return data[channel_i];
}
