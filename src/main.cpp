#include <iostream>

#include "greeter.h"

int main() {
    Greeter greeter;
    std::cout << greeter.get_greeting() << std::endl;
    return 0;
}
