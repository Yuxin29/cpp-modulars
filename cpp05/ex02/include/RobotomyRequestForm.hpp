#pragma once

#include "AForm.hpp"

// private：child class cannot visit, only self can visit
// protected：child class can visit
class RobotomyRequestForm
    : Public AForm
    // : Form  default inharitance only inharites the private attr, needs a pubic one
{
private:
	const std::string   _target;
	
public:
	RobotomyRequestForm::RobotomyRequestForm(std::string target)
    RobotomyRequestForm(const RobotomyRequestForm& other);               
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    const std::string& getTarget() const;

    void executeAction() const;
};