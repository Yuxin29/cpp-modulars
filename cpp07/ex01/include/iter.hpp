#pragma once

#include <string>
#include <iostream>
#include <cstdint>

// Implement a function template iter that takes 3 parameters and returns nothing.
// •The first parameter is the address of an array.
// •The second one is the length of the array.
// •The third one is a function that will be call on every element of the array
template <typename T>
void iter(T *arr, size_t length, void (*ft)(T &))
{
    for (size_t i = 0; i < length; i++)
        ft(arr[i]);
}
