#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _signed = false;
    
    void checkGrade(int grade) const;
	
public:
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);               
    AForm& operator=(const AForm &other);
    ~AForm();

    const std::string&  getName() const;
    int                 getGradeToSign() const;
    int                 getGradeToExecute() const;
    bool                getSignedOrNot() const;

    void            beSigned(const Bureaucrat& b);
    // !!!!!!!!!!!!!  NEW HEWE !!!!!!!!!!!!!!
    void            execute(Bureaucrat const & executor) const;
    //pure virtual. so the child can all use it and the child must inplement it themselves
    virtual void    executeAction() const = 0;

    class GradeTooHighException :public std::exception{
        const char* what() const throw();
    };

    class GradeTooLowException :public std::exception{
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);