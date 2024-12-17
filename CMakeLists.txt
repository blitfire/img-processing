cmake_minimum_required(VERSION 3.0)
project(img_processing)

set(CMAKE_CXX_STANDARD 20)

add_executable(img_processing main.cpp stb/stb_image.h stb/stb_image_write.h
        ImageData.cpp
        ImageData.h
        stb-headers.h
        JPEG.cpp
        JPEG.h
        PNG.cpp
        PNG.h
        stb/stb_image.h
        stb/stb_image_write.h
        ImageProc.cpp
        ImageProc.h
        Pixel.cpp
        Pixel.h)
