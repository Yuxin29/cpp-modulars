#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed." << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "";    
}

Brain::Brain(const Brain& other){
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

//do I need to check identical case here
// -->> good habit, but not necessary here, because all static
Brain& Brain::operator=(const Brain &other){
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    return *this;
}
    
Brain::~Brain(){
    std::cout << "Brain deconstructed." << std::endl;
}

void Brain::set_idea(int index, std::string idea)
{
    if (index < 100 && index >= 0)
        _ideas[index] = idea;
    return ;
}

std::string Brain::get_idea(int index) const
{
    if (index < 100 && index >= 0)
        return (_ideas[index]);
    return "";
}