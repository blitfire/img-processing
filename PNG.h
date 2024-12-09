//
// Created by george on 09/12/24.
//

#ifndef PNG_H
#define PNG_H

#include "Image.h"
#define PNG_CHANNELS 4

class PNG final : public Image {
public:
    explicit PNG(const char *path) : Image{path, PNG_CHANNELS} {}

    void save(const char *path) const override;
};



#endif //PNG_H
