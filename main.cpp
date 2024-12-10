#include <iostream>
#include <stdexcept>
#include "JPEG.h"


int main() {
    try {
        JPEG spitfire {"../test-images/spitfire.jpg"};
        if (const std::optional<Pixel> maybe_p = spitfire.getPixel(300, 40); maybe_p != std::nullopt) {
            Pixel p = maybe_p.value();
            std::cout << "R: " << +p[0] << std::endl
                    << "G: " << +p[1] << std::endl
                    << "B: " << +p[2] << std::endl;
        }
    } catch (std::out_of_range &e) {
        std::cerr << e.what() << std::endl;
    } catch (std::ios_base::failure &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}