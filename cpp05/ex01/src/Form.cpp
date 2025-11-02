#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    :_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    checkGrade(gradeToSign);
}

Form::Form(const Form& other)
    : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
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
