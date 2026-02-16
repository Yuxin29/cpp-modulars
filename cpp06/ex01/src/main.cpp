#include "Serializer.hpp"
#include <iostream>

int main() {
    Data test;
    test.n = 42;
    test.str = "hello";

    uintptr_t raw = Serializer::serialize(&test);
    Data* result = Serializer::deserialize(raw);
    std::cout << "test printing: " << &test << std::endl;
    std::cout << "raw integer: " << raw << std::endl;
    std::cout << "raw integer in hex: 0x" << std::hex << raw << std::dec << std::endl;
    std::cout << "ptr printing: " << result << std::endl;

    if (result == &test)
        std::cout << "working" << std::endl;
    
    return 0;
}