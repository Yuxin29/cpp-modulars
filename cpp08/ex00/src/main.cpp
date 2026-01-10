#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>

// std::vector<int>	Contiguous memory (all elements stored next to each other), Access: Supports random access via operator[] (O(1))
// std::deque<int>	Fast at both front and back, slower in the middle
// std::list<int>	No random access (operator[] not supported), must traverse with iterators
// std::forward_list<int> No random access, can only traverse forward
int main() {
    std::cout << "------ testing vector ------\n";
    std::vector<int> v = {1, 2, 4, 42, 100};
    try{
        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << "Found in vector: " << *it << std::endl << std::endl;
    }
    catch (std::runtime_error &e){
        std::cout << e.what() << std::endl << std::endl;
    }

    std::cout << "------ testing deque ------\n";
    std::deque<int> d = {1, 2, 4, 42, 100};
    try{
        std::deque<int>::iterator it = easyfind(d, 42);
        std::cout << "Found in deque: " << *it << std::endl << std::endl;
    }
    catch (std::runtime_error &e){
        std::cout << e.what() << std::endl << std::endl;
    }

    std::cout << "------ testing list ------\n";
    std::list<int> l = {1, 2, 4, 42, 100};
    try{
        std::list<int>::iterator it = easyfind(l, 42);
        std::cout << "Found in list: " << *it << std::endl << std::endl;
    }
    catch (std::runtime_error &e){
        std::cout << e.what() << std::endl << std::endl;
    }

    std::cout << "------ forward_list vector ------\n";
    std::forward_list<int> f = {1, 2, 4, 42, 100};
    try{
        std::forward_list<int>::iterator it = easyfind(f, 99);
        std::cout << "Found in forward_list: " << *it << std::endl << std::endl;
    }
    catch (std::runtime_error &e){
        std::cout << e.what() << std::endl << std::endl;
    }

    return 0;
}