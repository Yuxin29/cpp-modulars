#include "Bureaucrat.hpp"
#include "Form.hpp"

const char* GradeTooHighException::what() const throw()
{   
    return "grade too high";
}

const char* GradeTooLowException::what() const throw()
{   
    return "grade too low";
}

void checkGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
     if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    :_name(name){
    checkGrade(grade);
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
    this->_grade = other._grade;
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
// Ifthe grade is out of range, both of them will throw the same exceptions as the constructor.
//incrementing a grade 3 should give a grade 2 to the bureaucrat.
void Bureaucrat::incre_grade(){
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decre_grade(){
    checkGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::signForm(Form& f){
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout << _name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}