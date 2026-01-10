#pragma once

#include <string>
#include <iostream>
#include <vector>

class Span{
private:
    // Develop a Span class that can store a maximum of N integers. 
    // N is an unsigned int variable and will be the only parameter passed to the constructor.
    unsigned int        _max;
    std::vector<int>    _numbers;

public:
    Span(unsigned int N);
    Span(const Span& another);
    Span& operator=(const Span &other);
    ~Span(); 

    void addNumber(int number);

    int shortestSpan() const;
    int longestSpan() const;

    // Last but not least, it would be wonderful to fill your Span using a range of iterators.
    // Making thousands calls to addNumber() is so annoying. 
    // Implement a member function to add many numbers to your Span in one call.
    // If you don’t have a clue, study the Containers. 
    // Some member functions take a range of iterators in order to add a sequence of elements to the container.
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end){
        size_t new_range = std::distance(begin, end);

        if (_numbers.size() + new_range > _max)
            throw std::runtime_error("the new Span will overflow");

        _numbers.insert(_numbers.end(), begin, end);
    }

};