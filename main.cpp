#include <iostream>
#include <stdexcept>
#include "JPEG.h"


int main() {
    Pixel p;
    try {
        JPEG spitfire {"../test-images/spitfire.jpg"};
        p = spitfire.getPixel(300, 40);
        std::cout << "R: " << +p[0] << std::endl
                << "G: " << +p[1] << std::endl
                << "B: " << +p[2] << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    } catch (std::ios_base::failure &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}