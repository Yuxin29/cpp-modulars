#pragma once

#include <vector>
#include <stdexcept>
#include <iterator>

// Develop a Span class that can store a maximum of N integers. 
// N is an unsigned int variable and will be the only parameter passed to the constructor.
class Span{
private:
    unsigned int        _max;
    std::vector<int>    _numbers;

public:
    Span(unsigned int N);
    Span(const Span& another);
    Span& operator=(const Span &other);
    ~Span(); 

    void addNumber(int number);

    long long shortestSpan() const;
    long long longestSpan() const;

    // Last but not least, it would be wonderful to fill your Span using a range of iterators.
    // Implement a member function to add many numbers to your Span in one call.
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end){
        size_t new_range = static_cast<size_t>(std::distance(begin, end));
        if (_numbers.size() + new_range > _max)
            throw std::runtime_error("the new Span will overflow");
        _numbers.insert(_numbers.end(), begin, end);
    }
};