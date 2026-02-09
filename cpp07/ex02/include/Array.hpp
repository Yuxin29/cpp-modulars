#pragma once

//Develop a class template Array that contains elements of type T and implements the following behavior and functions:
template <typename T>
class Array {
private:
    T*              _ptr;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);               
    Array& operator=(const Array &other);
    ~Array();

    unsigned int size() const;
    T& operator[](unsigned int index);
};

#include "Array.tpp"