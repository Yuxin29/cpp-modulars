#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2){
        std::cerr << "Error: no int arrays\n";
        return 1;
    }
    try{
        PmergeMe test(av);
        test.sequenceSort();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        return 1;
    }
}

// testing examples
//./PmergeMe 3 5 9 7 4
//./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`