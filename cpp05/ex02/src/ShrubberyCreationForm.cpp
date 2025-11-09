#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    :AForm("other forms", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    :AForm(other), _target(other._target) {
}            
    
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

const std::string& ShrubberyCreationForm::getTarget() const{
    return _target;
}

// just a tree
// std::ofstream file(std::string filename)
void ShrubberyCreationForm::executeAction() const{
    std::ofstream file((_target + "_Shrubbery")); // create and open outfile
    if (!file.is_open()) {
        std::cout << "Error: cannot open output file." << std::endl;
        return;
    }
    file << "        /\\\n"
        <<  "       /  \\\n"
        <<  "      / /\\ \\\n"
        <<  "     / /  \\ \\\n"
        <<  "    / /    \\ \\\n"
        <<  "   / /      \\ \\\n"
        <<  "  /_/________\\_\\\n"
        <<  "       ||||\n"
        <<  "       ||||\n"
        <<  "       ||||\n"
        <<  "       ||||\n";
    file.close();
}
