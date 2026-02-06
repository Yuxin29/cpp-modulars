#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>	//setw
#include <string>	//resize, append

# define MAX_LENGTH 10

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

public:
	void		getContact();
	void		printContactNames(int i);
	void		printContact();
}; 

#endif