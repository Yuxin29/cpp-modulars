#pragma once

#include "AForm.hpp"

// private：child class cannot visit, only self can visit
// protected：child class can visit
class ShrubberyCreationForm
    : public AForm
    // : Form  default inharitance only inharites the private attr, needs a pubic one
{
private:
	const std::string   _target;
	
public:
	ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);               
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    const std::string& getTarget() const;

    void executeAction() const;
};