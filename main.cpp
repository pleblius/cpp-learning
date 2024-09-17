#include "sine.h"
#include <iostream>

int main() {
    Sine s = Sine(1, 360, 15);

    std::cout << "Post-fix test" << "\n";

    for (int i = 0; i < 25; ++i) {
        std::cout << s++ << "\n";
    }

    std::cout << "Pre-fix test" << "\n";
    s = Sine(1, 360, 30);

    for (int i = 0; i < 12; ++i) {
        std::cout << ++s << "\n";
    }

    std::cout << "Wavelength test" << "\n";

    s = Sine(1, 180, 30);

    for (int i = 0; i < 24; ++i) {
        std::cout << s++ << "\n";
    }
    
    return(0);
}
