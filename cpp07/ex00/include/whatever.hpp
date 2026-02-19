#pragma once

// why templete;
// without templete, the belows all need to be defined
// int swap(int a, int b);          // only int
// float swap(float a, float b);    // only float 
// char swap(char a, char b);       // only int

// swap: Swaps the values of two given arguments. Does not return anything.
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// min: Compares the two values passed in its arguments and returns the smallest one. 
// If the two of them are equal, then it returns the second one.
template <typename T>
const T& min(const T& a, const T& b)
{
    if (a < b)
        return a;
    return b;
}

// max: Compares the two values passed in its arguments and returns the greatest one.
// If the two of them are equal, then it returns the second one.
template <typename T>
const T& max(const T& a, const T& b)
{
    if (a > b)
        return a;
    return b;
}