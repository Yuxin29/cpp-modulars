
#include "Span.hpp"

// Test your Span at least with a minimum of 10 000 numbers. More would be even better.
int main( void )
{
    std::cout << "--------- basic test---------\n";
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << "--------- large number test---------\n";
    Span sp_large = Span(100);
    sp_large.addNumber(6);
    sp_large.addNumber(3);
    sp_large.addNumber(17);
    sp_large.addNumber(9);
    sp_large.addNumber(11);
    std::cout << sp_large.shortestSpan() << std::endl;
    std::cout << sp_large.longestSpan() << std::endl;
    return 0;
}

// Should output:
// $> ./ex01
// 2
// 14
// $>

