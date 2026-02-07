#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

const char* AForm::GradeTooHighException::what() const throw(){   
    return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){   
    return "grade too low";
}

void AForm::checkGrade(int grade) const{
    if (grade < 1)
        throw GradeTooHighException();
     if (grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    :_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
    checkGrade(gradeToSign);
    checkGrade(gradeToExecute);
}

AForm::AForm(const AForm& other)
    : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    this->_signed = other._signed;
}            
    
AForm& AForm::operator=(const AForm &other){
    this->_signed = other._signed;
    return *this;
}

AForm::~AForm(){
}

const std::string& AForm::getName() const{
    return _name;
}

int AForm::getGradeToSign() const{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const{
    return _gradeToExecute;
}

bool AForm::getSignedOrNot() const{
    return _signed;
}

void AForm::beSigned(const Bureaucrat& b){
    if (_signed)
        throw std::runtime_error("AForm already signed");
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// !!!!!!!!!!!!!  NEW HEWE !!!!!!!!!!!!!!
// Now, add the execute(Bureaucrat const & executor) const member function to the base form 
// and implement a function to execute the form’s action of the concrete classes. 
// You have to check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. 
// Otherwise, throw an appropriate exception.
void AForm::execute(Bureaucrat const & executor) const {
    if (_signed == false)
        throw std::runtime_error("AForm not signed, cannot execute.");
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    this->executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName() << ", grade to Sign " << f.getGradeToSign () << ", grade to Execute " << f.getGradeToExecute () << ", signed or not: " << f.getSignedOrNot() <<  ".";
    return os;
}