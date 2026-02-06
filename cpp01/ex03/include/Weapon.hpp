# pragma once

#include <string>
#include <iostream>

// • A private attribute type, which is a string.
// • A getType() member function that returns a const reference to type.
// • A setType() member function that sets type using the new one passed as parameter
class Weapon
{
private:
    std::string type;
    
public:
    Weapon(std::string type);
	~Weapon();

    const std::string& getType(void);
    void setType(std::string new_type);
};
