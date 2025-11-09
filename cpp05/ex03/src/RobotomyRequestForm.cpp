#include "RobotomyRequestForm.hpp"
#include <random>  

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    :AForm("other forms", 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    :AForm(other), _target(other._target) {
}            
    
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

const std::string& RobotomyRequestForm::getTarget() const{
    return _target;
}

// unsigned seed = rd(); random seed get a ramdom seed from hardware
// generate a random nbr using this seed.
//define a range
void RobotomyRequestForm::executeAction() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    std::cout << "zzzzzzzzzzzzzzz" << std::endl;
    if (dist(gen))
        std::cout << _target << " has been robotomized successfull." << std::endl;
    else
        std::cout << _target << ", the robotomy failed" << std::endl;
}
