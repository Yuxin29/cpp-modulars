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

    // it needs to be nested, so repeateance is unavoidable
    class GradeTooHighException :public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException :public std::exception
    {
        const char* what() const throw();
    };

    virtual void beSigned(const Bureaucrat& b);
    // !!!!!!!!!!!!!  NEW HEWE !!!!!!!!!!!!!!
    void execute(Bureaucrat const & executor) const;
    virtual void executeAction() const = 0; //pure virtual. so the child can all use it
};

//an overload of the insertion («) operator that prints all the AForm’s inAFormations.
std::ostream& operator<<(std::ostream& os, const AForm& f);