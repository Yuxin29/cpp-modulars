#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    (void) ac;
    try{
        PmergeMe test(av);
        test.sequenceSort();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

// testing examples
//./PmergeMe 3 5 9 7 4
//./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`