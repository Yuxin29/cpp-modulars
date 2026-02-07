#include "Bureaucrat.hpp"
#include <stdexcept>

// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
// Bureaucrat::GradeTooHighException  or   Bureaucrat::GradeTooLowException.
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {   
    return "grade too low";
}

//internal helper function
void Bureaucrat::checkGrade(int grade) const{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

//const var must be initiated at the begining of the declaration
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    :_name(name) {
    checkGrade(grade);
    _grade = grade;
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

// Implement also two member functions to increment or decrement the bureaucrat grade. 
// If the grade is out of range, both of them will throw the same exceptions as the constructor.
void Bureaucrat::incrementGrade(){
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade(){
    checkGrade(_grade + 1);
    _grade++;
}

// you will implement an overload of the insertion («) operator to print something like
// <name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
