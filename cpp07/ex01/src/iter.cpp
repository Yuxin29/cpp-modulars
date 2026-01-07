#include "iter.hpp"

// pointer to int
// uintptr_t raw = reinterpret_cast<uintptr_t>(pointer); // 指针 → 整数
uintptr_t Serializer::serialize(Data* ptr){
    return  reinterpret_cast<uintptr_t>(ptr);
}

// int to pointer
// Data* ptr = reinterpret_cast<Data*>(raw);            // 整数 → 指针
Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}