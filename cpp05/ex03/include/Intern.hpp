#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:

public:
    AForm* makeForm(const std::string& name, const std::string& tar);
};
