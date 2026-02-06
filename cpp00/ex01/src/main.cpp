#include "PhoneBook.hpp"

// On program start-up, the phonebook is empty 
// and the user is prompted to enter one of three commands. 
// The program only accepts ADD, SEARCH and EXIT.
int main()
{
    PhoneBook   book;
    std::string cmd;
    while (true){
        std::cout << "Enter command please (ADD / SEARCH / EXIT): ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            book.addContact();
        else if (cmd == "SEARCH")
            book.searchContact();
        else if (cmd == "EXIT")
            break;
    }
	return (0);
}

// code reveiew feedback
//I should guild my getline with null check after it
