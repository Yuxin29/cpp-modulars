#include "Serializer.hpp"
#include <iostream>

// pointer to int
// uintptr_t raw = reinterpret_cast<uintptr_t>(pointer);
// reinterpret_cast = low-level bit reinterpretation
//It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr){
    return  reinterpret_cast<uintptr_t>(ptr);
}

// int to pointer
// Data* ptr = reinterpret_cast<Data*>(raw); 
// It takes an unsigned integer parameter and converts it to a pointer to Data.           
Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}