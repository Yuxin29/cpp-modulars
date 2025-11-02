#include "Form.hpp"

Form::Form(){
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    :_name(name){
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
    _gradeToSign = gradeToSign;
    _gradeToExecute = gradeToExecute;
    _signed = False;
}

Form::Form(const Bureaucrat& other){
    this->_signed = other._signed;
}            
    
Form& Form::operator=(const Form &other){
    this->_signed = other._signed;
    return *this;
}

Form::~Bureaucrat(){
}

void Form::checkGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
     if (grade > 150)
        throw GradeTooLowException();
}

void beSigned(Bureaucrat& b);
void signForm(Bureaucrat& b);

const char* Bureaucrat::GradeTooHighException::what() const throw()
{   
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{   
    return "grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}