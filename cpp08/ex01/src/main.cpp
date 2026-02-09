#include "Span.hpp"
#include <iostream>
#include <ctime>

// Test your Span at least with a minimum of 10 000 numbers. More would be even better.
int main( void )
{
    std::cout << "--------- basic test---------\n";
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        sp.addNumber(42);
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\n";
    
    std::cout << "--------- large number test---------\n";
    Span sp_large = Span(10);
    std::vector<int> v = {1, 3, 8 ,15};
    try {
        sp_large.addRange(v.begin(), v.end());
        std::cout << "added\n";
        sp_large.addRange(v.begin(), v.end());
        std::cout << "added\n";
        sp_large.addRange(v.begin(), v.end()); // should throw
        std::cout << "added\n";
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "\n";

    std::cout << "\n--------- 10000 numbers test ---------\n";
    Span big(10000);
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; i++)
        big.addNumber(std::rand());
    std::cout << "shortest: " << big.shortestSpan() << std::endl;
    std::cout << "longest : " << big.longestSpan() << std::endl;

    return 0;
}


// Should output:
// $> ./ex01
// 2
// 14
// $>

