cmake_minimum_required(VERSION 3.10)
project(img_processing)

set(CMAKE_CXX_STANDARD 20)

add_executable(img_processing main.cpp
#        ImageData.cpp
#        ImageData.h
        stb-headers.h
        JPEG.cpp
        JPEG.h
        PNG.cpp
        PNG.h
        stb/stb_image.h
        stb/stb_image_write.h
        Pixel.cpp
        Pixel.h)
