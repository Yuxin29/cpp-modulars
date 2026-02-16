#pragma once

#include <string>
#include <cstdint>

//uintptr_t is an unsighned int type that guaranteed to be able to hold a ptr without losing info
struct Data{
    int         n;
    std::string str;
};

class Serializer
{
private:
    // can not be initializable
    Serializer() = delete;

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};