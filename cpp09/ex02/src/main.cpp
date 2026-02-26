#include "PmergeMe.hpp"

#include <iostream>

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

    return 0;
}

// $> ./PmergeMe 3 5 9 7 4
// Before: 3 5 9 7 4
// After: 3 4 5 7 9
// Time to process a range of 5 elements with std::[..] : 0.00031 us
// Time to process a range of 5 elements with std::[..] : 0.00014 us

// Your program must be able to handle at least 3000 different integers.
// $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
// Before: 141 79 526 321 [...]
// After: 79 141 321 526 [...]
// Time to process a range of 3000 elements with std::[..] : 62.14389 us
// Time to process a range of 3000 elements with std::[..] : 69.27212 us

// $> ./PmergeMe "-1" "2"
// Error

// $> # For OSX USER:
// $> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
// [...]
// $>