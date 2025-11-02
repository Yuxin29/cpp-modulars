#pragma once

#include <string>
// #include <iostream>
// #include <stdexcept>

class Form
{
private:
	const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _signed; //from 1 to 150: highest to lowese
	
public:
    Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);               
    Form& operator=(const Form &other);
    ~Form();

    void beSigned(Bureaucrat& b);
    void signForm(Bureaucrat& b);

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