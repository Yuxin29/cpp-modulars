#pragma once

#include "AForm.hpp"

class Intern
{
private:

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& name, const std::string& tar);
};
