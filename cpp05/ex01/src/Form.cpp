#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

const char* Form::GradeTooHighException::what() const throw(){   
    return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw(){   
    return "grade too low";
}

void Form::checkGrade(int grade) const{
    if (grade < 1)
        throw GradeTooHighException();
     if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    :_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
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

const std::string& Form::getName() const{
    return _name;
}

int Form::getGradeToSign() const{
    return _gradeToSign;
}

int Form::getGradeToExecute() const{
    return _gradeToExecute;
}

bool Form::getSignedOrNot() const{
    return _signed;
}

void Form::beSigned(const Bureaucrat& b){
    if (_signed)
        throw std::runtime_error("Form already signed");
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << ", grade to Sign " << f.getGradeToSign () << ", grade to Execute " << f.getGradeToExecute () << ", signed or not: " << f.getSignedOrNot() <<  ".";
    return os;
}