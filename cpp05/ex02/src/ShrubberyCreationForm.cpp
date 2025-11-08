#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    :AForm("other forms", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    Aform(other), _target(other._target) {
    this->_signed = other._signed;
}            
    
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if (this != &other)
    {
        AForm::operator=(other);
        this->_signed = other._signed;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

const std::string& ShrubberyCreationForm::getTarget() const{
    return _target;
}

//just a tree
void ShrubberyCreationForm::executeAction() const{
    std::ofstream file((_target + "_Shrubbery").c_str())
    if (!file.is_open())
    {
        std::cout << "Error: cannot open output file." << std::endl;
        return;
    }
    file << "        /\\\n";
            "       /  \\\n";
            "      / /\\ \\\n";
            "     / /  \\ \\\n";
            "    / /    \\ \\\n";
            "   / /      \\ \\\n";
            "  /_/________\\_\\\n";
            "       ||||\n";
            "       ||||\n";
            "       ||||\n";
            "       ||||\n";
    file.close();
}
