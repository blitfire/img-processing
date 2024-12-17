cmake_minimum_required(VERSION 3.0)
project(img_processing)

set(CMAKE_CXX_STANDARD 20)

add_executable(img_processing main.cpp stb/stb_image.h stb/stb_image_write.h
        stb-headers.h
        JPEG.cpp
        JPEG.h
        PNG.cpp
        PNG.h
        PixelRef.cpp
        PixelRef.h
        stb/stb_image.h
        stb/stb_image_write.h
        image-data-utils.cpp
        image-data-utils.h)
