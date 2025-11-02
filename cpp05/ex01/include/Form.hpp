#pragma once

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _signed; // true for signed, false for not signed
	
public:
    Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);               
    Form& operator=(const Form &other);
    ~Form();

    const std::string getName();
    void beSigned(Bureaucrat& b);
    void signForm(Bureaucrat& b);
};