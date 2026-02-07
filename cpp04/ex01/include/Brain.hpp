#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	std::string _ideas[100];

public:
	Brain();
    Brain(const Brain& other);               
    Brain& operator=(const Brain &other);
    ~Brain();

    void set_idea(int index, std::string idea);
    std::string get_idea(int index) const;
};
