#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    :AForm("other forms", 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    :AForm(other), _target(other._target) {
}            
    
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

const std::string& PresidentialPardonForm::getTarget() const{
    return _target;
}

//just a tree
void PresidentialPardonForm::executeAction() const{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
