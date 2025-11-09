#pragma once

#include <string>
#include <iostream>

// _grade; from 1 to 150: highest to lowest
class Bureaucrat
{
private:
	const std::string   _name;
    int                 _grade;
    void checkGrade(int grade) const;
	
public:
	Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);               
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    // it needs to be nested, indicated by the subject example
    class GradeTooHighException :public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException :public std::exception
    {
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
