
#include "Span.hpp"

Span::Span(unsigned int N) :_max(N){
}

Span::Span(const Span& another)
    :_max(another._max), _numbers(another._numbers){
}
    
Span& Span::operator=(const Span &other){
    if (this != &other){
        _max = other._max;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span(){
}

// This class will have a member function called addNumber() to add a single number to the Span. 
// It will be used in order to fill it. 
// Any attempt to add a new element if there are already N elements stored should throw an exception.
void Span::addNumber(int number){
    if (_numbers.size() >= _max)
        throw std::runtime_error("Span is already full");
    _numbers.push_back(number);
}

// Next, implement two member functions: shortestSpan() and longestSpan()
// They will respectively find out the shortest span or the longest span (or distance,
// if you prefer) between all the numbers stored, and return it. 
// If there are no numbers stored, or only one, no span can be found. 
// Thus, throw an exception.
int Span::shortestSpan(){
    if (_numbers.size() < 2)
        throw std::runtime_error("Span is too small");
    std::vector<int> cp = _numbers;
    std::sort(cp.begin(), cp.end());
    int min_span = cp[1] - cp[0];
    for (size_t i = 0; i < cp.size(); i++){
        if ((cp[i + 1] - cp[i]) < min_span) 
            min_span = cp[i + 1] - cp[i];
    }
    return min_span;
}

int Span::longestSpan(){
    if (_numbers.size() < 2)
        throw std::runtime_error("Span is too small");
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return (max - min);
}