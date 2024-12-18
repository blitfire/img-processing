#include <iostream>
#include <stdexcept>
#include "JPEG.h"

int main() {
    try {
        JPEG spitfire {"../test-images/spitfire.jpg"};

    } catch (std::ios_base::failure &e) {
        std::cerr << e.what() << std::endl;
    }
}