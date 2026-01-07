
#include "Array.hpp"

int main()
{
    std::cout << "testing default constructor" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl << std::endl;
    
    std::cout << "testing default constructor with a size" << std::endl;
    Array<int> b(4);
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    std::cout << "b.size() = " << b.size() << std::endl << std::endl;
    
    std::cout << "testing accross bondary" << std::endl;
    try{
        std::cout << b[10] << std::endl;
    }
    catch (std::exception& e){
        std::cout << "acros boundary caught!" << std::endl << std::endl;
    }

    std::cout << "testing deep copying" << std::endl;
    Array<int> b(4);
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    std::cout << "b.size() = " << b.size() << std::endl << std::endl;

    return 0;
}
