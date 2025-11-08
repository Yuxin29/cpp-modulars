#pragma once

#include "AForm.hpp"

// private：child class cannot visit, only self can visit
// protected：child class can visit
class PresidentialPardonForm
    : public AForm
    // : Form  default inharitance only inharites the private attr, needs a pubic one
{
private:
	const std::string   _target;
	
public:
	PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& other);               
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    const std::string& getTarget() const;

    void executeAction() const;
};