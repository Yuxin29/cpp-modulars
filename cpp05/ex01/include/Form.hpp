#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
private:
	const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _signed = false; // true for signed, false for not signed
    
    void checkGrade(int grade) const;
	
public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);               
    Form& operator=(const Form &other);
    ~Form();

    const std::string& getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getSignedOrNot() const;

    void beSigned(const Bureaucrat& b);

    // it needs to be nested, so repeateance is unavoidable
    class GradeTooHighException :public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException :public std::exception
    {
        const char* what() const throw();
    };
};

//an overload of the insertion («) operator that prints all the form’s informations.
std::ostream& operator<<(std::ostream& os, const Form& f);