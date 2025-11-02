#include "Form.hpp"

Form::Form(){
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    :_name(name){
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
    _gradeToSign = gradeToSign;
    _gradeToExecute = gradeToExecute;
    _signed = false;
}

Form::Form(const Bureaucrat& other){
    this->_signed = other._signed;
}            
    
Form& Form::operator=(const Form &other){
    this->_signed = other._signed;
    return *this;
}

Form::~Form(){
}

const std::string Form::getName()
{
    return _name;
}

void Form::beSigned(Bureaucrat& b){
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}