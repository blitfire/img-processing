//
// Created by george on 09/12/24.
//

#include "JPEG.h"

#include "stb/stb_image_write.h"

void JPEG::save(const char *path) const {
    stbi_write_jpg(path,
        getWidth(),
        getHeight(),
        getChannels(),
        getBytes().data(),
        compression_quality);
}
