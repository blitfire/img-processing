//
// Created by george on 09/12/24.
//

#include "PNG.h"

#include "stb/stb_image_write.h"

void PNG::save(const char *path) const {
    stbi_write_png(path, width, height, channels, data.data(), width * channels);
}
