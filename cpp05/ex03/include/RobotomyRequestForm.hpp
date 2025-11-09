#pragma once

#include "AForm.hpp"

// : Form  default inharitance only inharites the private attr, needs a pubic one
class RobotomyRequestForm
    : public AForm
{
private:
	const std::string   _target;
	
public:
	RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);               
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    const std::string& getTarget() const;

    void executeAction() const;
};