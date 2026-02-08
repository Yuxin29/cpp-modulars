#include "iter.hpp"

template <typename T>
static void print(T &x)
{
    std::cout << x << std::endl;
}

template <typename T>
void plueOne(T &x) {
    if constexpr(std::is_arithmetic_v<T>) // C++17
        std::cout << x + 1 << std::endl;
    else
        std::cout << "Cannot add 1 to this type" << std::endl;
}

int main() {
    //testing int
    int intArr[4] = {0, 1, 2, 3};
    iter(intArr, 4, print<int>);
    iter(intArr, 4, plueOne<int>);

    //testing str
    std::string strArr[3] = {"hello", "summer", "goodbye"};
    iter(strArr, 3, print<std::string>);
    iter(strArr, 3, plueOne<std::string>);
    
    //testing char
    char chaArr[3] = {'a','b','c'};
    iter(chaArr, 3, print<char>);
    iter(chaArr, 3, plueOne<char>);
    
    return 0;
}