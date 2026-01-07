
#include "Array.hpp"

// new[]        allocate an array in a stack
// delete[]     free the array in a stack

// Construction with no parameter: Creates an empty array.
// Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
template <typename T>
Array<T>::Array() :_ptr(nullptr), _size(0):{
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n){
    _ptr = new T[n]();
}

// Construction by copy and assignment operator. 
// In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
template <typename T>
Array<T>::Array(const Array<T>& other) :_size(other._size){
    _ptr = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _ptr[i] = other._ptr[i]; // deep copy
}             
// Shallow copy: _ptr = other._ptr; 

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other){
    if (this != &toher)
    {
        delete[] _ptr;
        _size = other._size;
        _ptr = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _ptr[i] = other._ptr[i]; // deep copy
    }
    return *this;
}