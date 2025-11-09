#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

//const var must be initiated at the begining of the declaration
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :_name(name) {
    checkGrade(grade);
    _grade = grade;
}

void Bureaucrat::checkGrade(int grade) const{
    if (grade < 1)
        throw GradeTooHighException();
     if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) 
:_name(other._name), _grade(other._grade){
}            
    
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){
}

const std::string& Bureaucrat::getName() const{
    return _name;
}

int Bureaucrat::getGrade() const{
    return _grade;
}

//Implement also two member functions to increment or decrement the bureaucrat grade. 
// If the grade is out of range, both of them will throw the same exceptions as the constructor.
void Bureaucrat::incrementGrade(){
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade(){
    checkGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::signForm(Form& f){
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
        std::cout << _name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){   
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){   
    return "grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}