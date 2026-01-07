#pragma once

#include <string>
#include <iostream>
#include <cstdlib> //rand

//Develop a class template Array that contains elements of type T and 
// that implements the following behavior and functions:
template <typename T>
class Array {
private:
    T*              _ptr;
    unsigned int    _size;
public:
    // Construction with no parameter: Creates an empty array.
    // Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
    Array();
    Array(unsigned int n);
    // Construction by copy and assignment operator. 
    // In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
    Array(const Array& other);               
    Array& operator=(const Array &other);

    ~Array() {}

    // A member function size() that returns the number of elements in the array. 
    // This member function takes no parameter and musn’t modify the current instance.
    size_t size();

    // You MUST use the operator new[] to allocate memory. 
    // Preventive allocation (allocating memory in advance) is forbidden. 
    // Your program must never access non-allocated memory.

    // Elements can be accessed through the subscript operator: [ ].

    // When accessing an element with the [ ] operator, if its index is out of bounds, 
    // an std::exception is thrown.

};