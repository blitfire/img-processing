#include <iostream>
#include <cstdlib>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

int main() {
    int width, height, channels;
    unsigned char *img = stbi_load("../test-images/spitfire.jpg", &width, &height, &channels, 0);
    if (img == nullptr) {
        std::cerr << "Error in loading the image" << std::endl;
        std::exit(1);
    }
    std::cout << "Image details: " << std::endl
                << "Width: " << width << std::endl
                << "Height: " << height << std::endl
                << "Channels: " << channels << std::endl;
    return 0;
}