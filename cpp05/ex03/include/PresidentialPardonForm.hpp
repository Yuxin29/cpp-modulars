#pragma once

#include "AForm.hpp"

// : Form  default inharitance only inharites the private attr, needs a pubic one
class PresidentialPardonForm
    : public AForm
{
private:
	const std::string   _target;
	
public:
	PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);               
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    const std::string& getTarget() const;

    void executeAction() const;
};