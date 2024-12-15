//
// Created by george on 12/12/24.
//

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "stb-headers.h"
#include "ImageProc.h"
#include "JPEG.h"
#include "PixelRef.h"

ImageProc::ImageProc(std::string_view path) {
    // Check type of image with image header read through standard IO
}

void ImageProc::scaleBrightness(ImageData &img, float scale) {
    int width = img.getWidth();
    int height = img.getHeight();
    int channels = img.getChannels();

    try {
        for (int i {}; i < width; i++) {
            for (int j {}; j < height; j++) {
                PixelRef pixel = img.getPixel(i, j).value();
                for (int c{}; c < channels; c++) {
                    unsigned char channel_value = pixel[c];
                    float new_value = std::round(static_cast<float>(channel_value) * scale);
                    pixel[c] = new_value < 255.0f ? static_cast<unsigned char>(new_value) : 255;
                }
            }
        }
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
        
    }
}
