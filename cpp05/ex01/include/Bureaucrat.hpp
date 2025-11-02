#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
	const std::string   _name;
    int                 _grade; //from 1 to 150: highest to lowese
    void checkGrade(int grade);
	
public:
    Bureaucrat();
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);               
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;
    void incre_grade();
    void decre_grade();

    class GradeTooHighException
        :public std::exception //inhariting exception from stdexcept
    {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException
        :public std::exception //inhariting exception from stdexcept
    {
        public:
        const char* what() const throw();
    };
};

//later
// you will implement an overload of the insertion («) operator to print something like
// <name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
// either a         Bureaucrat::GradeTooHighException 
// or a             Bureaucrat::GradeTooLowException.
