#include <iostream>
#include "Beleza.h"

int main(int argc, char *argv[]) {
    std::cout << "Beleza Game Engine\n";
    Beleza *beleza = new Beleza("Beleza", "0.0.3");
    delete beleza;
    return 0;
}
