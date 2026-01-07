#include "Serializer.hpp"

int main() {
    Data test;
    test.n = 42;
    test.str = "hello";

    uintptr_t raw = Serializer::serialize(&test);
    Data* result = Serializer::deserialize(raw);
    std::cout << "raw integer: " << raw << std::endl;
    std::cout << "test printing: " << &test << std::endl;
    std::cout << "result printing: " << result << std::endl;

    if (result == &test)
        std::cout << "working" << std::endl;
    
    return 0;
}