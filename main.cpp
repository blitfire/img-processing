#include <iostream>
#include "JPEG.h"

int main() {
    try {
        JPEG spitfire {"../test-images/spitfire.jpg"};
        spitfire.setCompressionQuality(90).flipH().write("../test-images/flipped-spitfire.jpg");
    } catch (std::ios_base::failure &e) {
        std::cerr << e.what() << std::endl;
    }
}