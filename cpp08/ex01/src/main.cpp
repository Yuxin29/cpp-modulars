
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
    Span sp_large = Span(10);
    std::vector<int> v = {1, 3, 8 ,15};
    sp_large.addRange(v.begin(), v.end());
    sp_large.addRange(v.begin(), v.end());
    sp_large.addRange(v.begin(), v.end());
    std::cout << sp_large.shortestSpan() << std::endl;
    std::cout << sp_large.longestSpan() << std::endl;
    return 0;
}

// Should output:
// $> ./ex01
// 2
// 14
// $>

