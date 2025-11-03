#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

//forward-declare: can use it here, but when compiling, need header
class AForm;

// _grade; from 1 to 150: highest to lowese
class Bureaucrat
{
private:
	const std::string   _name;
    int                 _grade;
    void checkGrade(int grade) const;
	
public:
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);               
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signAForm(AForm& f);

    // Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
    // Bureaucrat::GradeTooHighException  or   Bureaucrat::GradeTooLowException.
    // it needs to be nested
    class GradeTooHighException :public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException :public std::exception
    {
        const char* what() const throw();
    };

    // !!!!!!!!!!!!!  NEW HEWE !!!!!!!!!!!!!!
    // Lastly, add the executeForm(AForm const & form) member function to the Bureaucrat. 
    // It must attempt to execute the form. If it’s successful, print something like:
    // <bureaucrat> executed <form>
    // If not, print an explicit error message
    void executeForm(AForm const & form);

};

//later
// you will implement an overload of the insertion («) operator to print something like
// <name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
