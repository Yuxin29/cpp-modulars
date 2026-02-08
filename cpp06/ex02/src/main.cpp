#include "Base.hpp"
#include <ctime>

int main()
{
    // regenerate the ramdom seed
    // seed stored in global state for rand() to use
    std::srand(std::time(NULL));
    Base* test = generate();

    std::cout << "using ptr: \n";
    identify(test);
    std::cout << "using ref: \n";
    identify(*test);

    delete test;
    return 0;
}
