
#include "MutantStack.hpp"

// push()   Adds an element to the top of the stack 
// pop()    Removecs the element to the top of the stack 
// top()    Accesses (reads) the element at the top
// empty()  Returns true if the stack has no elements
// size()   Returns the number of elements currently in the stack
int main()
{
    MutantStack<int> mstack;

    std::cout << "---- testing push----\n";
    std::cout << "empty or not: " << mstack.empty() << std::endl;
    
    std::cout << "---- testing push----\n";
    mstack.push(5);
    mstack.push(17);
    std::cout << "empty or not: " << mstack.empty() << std::endl;
    std::cout << "Not the top is: " << mstack.top() << std::endl;

    std::cout << "---- testing pop----\n";
    mstack.pop();
    std::cout << "Not the top is: " << mstack.top() << std::endl;
    
    std::cout << "---- testing size----\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Now the size is: "<< mstack.size() << std::endl;

    MutantStack<int>::iterator it_begin = mstack.begin();
    MutantStack<int>::iterator it_end = mstack.end();
    ++it_begin;
    --it_begin;
    while (it_begin != it_end)
    {
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

