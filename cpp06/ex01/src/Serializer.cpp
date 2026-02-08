#include "Serializer.hpp"

// pointer to int
// uintptr_t raw = reinterpret_cast<uintptr_t>(pointer);
uintptr_t Serializer::serialize(Data* ptr){
    return  reinterpret_cast<uintptr_t>(ptr);
}

// int to pointer
// Data* ptr = reinterpret_cast<Data*>(raw);            
Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}