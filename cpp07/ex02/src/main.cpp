#include "Array.hpp"

int main()
{
    std::cout << "testing default constructor" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl << std::endl;
    
    std::cout << "testing default constructor with a size" << std::endl;
    Array<int> b;
    try {
        b = Array<int>(4);
        std::cout << "b.size() = " << b.size() << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    std::cout << "b.size() = " << b.size() << std::endl << std::endl;
    
    std::cout << "testing accross bondary" << std::endl;
    try{
        std::cout << b[10] << std::endl;
    }
    catch (std::exception& e){
        std::cout << "accros boundary caught!" << std::endl << std::endl;
    }

    std::cout << "testing deep copying" << std::endl;
    try 
    {
        Array<int> c = b;
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = c[i] + 100;
        for (unsigned int i = 0; i < c.size(); i++){
            std::cout << "b[" << i << "] = " << b[i] << std::endl;
            std::cout << "c[" << i << "] = " << c[i] << std::endl;
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
