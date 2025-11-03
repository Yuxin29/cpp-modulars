#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;


// private：child class cannot visit, only self can visit
// protected：child class can visit
class AForm
{
private:
	const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _signed = false; // true for signed, false for not signed
    
    void checkGrade(int grade) const;
	
public:
	AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);               
    AForm& operator=(const AForm &other);
    ~AForm();

    const std::string& getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getSignedOrNot() const;

    virtual void beSigned(const Bureaucrat& b) = 0; //make it completely pure abstract

    // it needs to be nested, so repeateance is unavoidable
    class GradeTooHighException :public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException :public std::exception
    {
        const char* what() const throw();
    };

    // !!!!!!!!!!!!!  NEW HEWE !!!!!!!!!!!!!!
    //Now, add the execute(Bureaucrat const & executor) const member function to the base form 
    // and implement a function to execute the form’s action of the concrete classes. 
    // You have to check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. 
    // Otherwise, throw an appropriate exception.
    void execute(Bureaucrat const & executor);
};

//an overload of the insertion («) operator that prints all the AForm’s inAFormations.
std::ostream& operator<<(std::ostream& os, const AForm& f);