#include "iter.hpp"

template <typename T>
static void print(T &x)
{
    std::cout << x << std::endl;
}

int main() {
    //testing int
    int intArr[4] = {0, 1, 2, 3};
    iter(intArr, 4, print<int>);

    //testing str
    std::string strArr[3] = {"hello", "summer", "goodbye"};
    iter(strArr, 3, print<std::string>);
    
    return 0;
}