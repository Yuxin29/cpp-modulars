#include "iter.hpp"
#include <type_traits>

template <typename T>
static void print(T x)
{
    std::cout << x << std::endl;
}

template <typename T>
void plueOne(T x) {
    if constexpr(std::is_arithmetic_v<T>) // C++17
        std::cout << x + 1 << std::endl;
    else
        std::cout << "Cannot add 1 to this type" << std::endl;
}

// Non-const reference (can modify)
template <typename T>
void doubleValue(T& x) {
    if constexpr(std::is_arithmetic_v<T>)
        x *= 2;
}

// Const reference (read-only)
template <typename T>
void showConst(const T& x) {
    std::cout << x << " ";
}

int main() {
    //testing int
    int intArr[4] = {0, 1, 2, 3};
    iter(intArr, 4, print<int>);
    iter(intArr, 4, plueOne<int>);
    iter(intArr, 4, doubleValue<int>);
    iter(intArr, 4, print<int>);

    // testing non-const and testing const reference
    const int cIntArr[3] = {10, 20, 30};
    //iter(cIntArr, 4, doubleValue<int>);
    iter(cIntArr, 3, showConst<int>); 
    std::cout << "\n";
    
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