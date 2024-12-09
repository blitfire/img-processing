//
// Created by george on 09/12/24.
//

#ifndef JPEG_H
#define JPEG_H

#include "Image.h"
#define JPEG_CHANNELS 3

class JPEG final : Image {
    int compression_quality {100};

public:
    explicit JPEG(const char *path) : Image{path, JPEG_CHANNELS} {}

    void save(const char *path) const override;

    void setCompressionQuality(const int quality) { compression_quality = quality; }
};



#endif //JPEG_H
