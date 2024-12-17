//
// Created by george on 17/12/24.
//

#include "image-data-utils.h"

float normaliseChannel(const unsigned char channel) {
    auto floating_channel = static_cast<float>(channel);
    floating_channel /= 255.0f;
    return floating_channel;
}
