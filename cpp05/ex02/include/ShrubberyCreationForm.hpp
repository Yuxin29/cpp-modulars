#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

#include "Form.hpp"

// private：child class cannot visit, only self can visit
// protected：child class can visit
class ShrubberyCreationForm
    : Public Form
    // : Form  default inharitance only inharites the private attr, needs a pubic one
{
private:
	const std::string   _target;
	
public:
	ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    ShrubberyCreationForm(const ShrubberyCreationForm& other);               
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    const std::string& getTarget() const;

    void createFile() const;
};