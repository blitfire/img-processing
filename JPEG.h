//
// Created by george on 09/12/24.
//

#ifndef JPEG_H
#define JPEG_H

#include "ImageData.h"
#define JPEG_CHANNELS 3

class JPEG final : public ImageData {
    int compression_quality {100};

public:
    explicit JPEG(const char *path) : ImageData{path, JPEG_CHANNELS} {}

    void save(const char *path) const override;

    void setCompressionQuality(const int quality) { compression_quality = quality; }
};



#endif //JPEG_H
