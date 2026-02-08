#include "Base.hpp"

//It randomly instantiates A, B, or C and returns the instance as a Base pointer. 
// rand() is a "pseudo-random"
Base* generate(void){
    int r = std::rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B; 
    return new C;
}

//It prints the actual type of the object pointed to by p: "A", "B", or "C".
// with a ptr, it will return a nullptr if it is a bad cast
void identify(Base* p){
    if (dynamic_cast<A *>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C *>(p))
        std::cout << "C\n";
    else 
        std::cout << "unknown\n";
}

//It prints the actual type of the object referenced by p: "A", "B", or "C". 
// Using a pointer inside this function is forbidden.
// with a ref, it will return a bad cast it is not the correct type.
void identify(Base& p){
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (std::bad_cast& e){}
    //in case of bad cast, it jumpes to next try
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (std::bad_cast& e){}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (std::bad_cast& e){}
    std::cout << "unknown\n";
}