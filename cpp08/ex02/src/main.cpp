#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> mstack;

    std::cout << "---- testing empty and push----\n";
    std::cout << "empty or not: " << mstack.empty() << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "empty or not: " << mstack.empty() << std::endl;
    std::cout << "Now the top is: " << mstack.top() << std::endl << std::endl;

    std::cout << "---- testing pop and top----\n";
    mstack.pop();
    std::cout << "Now the top is: " << mstack.top() << std::endl << std::endl;
    
    std::cout << "---- testing size----\n";
    mstack.push(3);
    mstack.push(4);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Now the size is: "<< mstack.size() << std::endl << std::endl;

    std::cout << "---- testing iterator----\n";
    MutantStack<int>::iterator it_begin = mstack.begin();
    MutantStack<int>::iterator it_end = mstack.end();
    while (it_begin != it_end){
        std::cout << *it_begin << std::endl;
        ++it_begin;
    }
    std::stack<int> s(mstack);

    return 0;
}

// If you run it a first time with your MutantStack, and a second time replacing the MutantStack with, 
// for example, a std::list, the two outputs should be the same. 

// Of course, when testing another container, 
// update the code below with the corresponding member functions (push() can become push_back()).

