#pragma once

#include <string>
#include <iostream>
#include <cstdint>

//uintptr_t is an unsighned int type that guaranteed to be able to hold a ptr without losing info

struct Data{
    int n;
    std::string str;
};

class Serializer
{
private:
    // can not be initializable
    Serializer() = delete;

public:
    //It takes a pointer and converts it to the unsigned integer type uintptr_t.
    static uintptr_t serialize(Data* ptr);
    //It takes an unsigned integer parameter and converts it to a pointer to Data.
    static Data* deserialize(uintptr_t raw);
};