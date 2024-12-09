#include <iostream>
#include <cstdlib>
#include "JPEG.h"


int main() {
    JPEG spitfire {"../test-images/spitfire.jpg"};

    std::cout << spitfire.getPixel(20, 110).size() << std::endl;
    return 0;
}