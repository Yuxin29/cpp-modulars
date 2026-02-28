#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    (void) ac;
    try{
        PmergeMe test(av);
        test.sequenceSort();
    }
    catch(const std::exception& e){
        std::cout << e.what() << '\n';
    }
}