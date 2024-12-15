//
// Created by george on 12/12/24.
//

#ifndef IMG_PROCESSING_IMAGEPROC_H
#define IMG_PROCESSING_IMAGEPROC_H

#include <string_view>
#include <memory>
#include "ImageData.h"

// Performs operations on images
class ImageProc {
    std::unique_ptr<ImageData> data;

public:
    explicit ImageProc(std::string_view path);
    void scaleBrightness(ImageData &img, float scale);
};


#endif //IMG_PROCESSING_IMAGEPROC_H
