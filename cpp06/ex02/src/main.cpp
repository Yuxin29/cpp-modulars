
#include "Base.hpp"

int main()
{
    Base* test = generate();

    std::cout << "using ptr: \n";
    identify(test);
    std::cout << "using ref: \n";
    identify(*test);

    return 0;
}
