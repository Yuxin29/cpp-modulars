#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
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

void AForm::checkGrade(int grade) const{
    if (grade < 1)
        throw GradeTooHighException();
     if (grade > 150)
        throw GradeTooLowException();
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

const char* AForm::GradeTooHighException::what() const throw(){   
    return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){   
    return "grade too low";
}


std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", grade to Sign " << f.getGradeToSign () << ", grade to Execute " << f.getGradeToExecute () << ", signed or not: " << f.getSignedOrNot() <<  ".";
    return os;
}