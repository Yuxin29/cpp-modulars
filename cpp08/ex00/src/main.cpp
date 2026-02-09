#include "easyfind.hpp"

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iostream>

template<typename Container>
static void test_container(Container &c, int value){
    try{
        auto it = easyfind(c, value);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
}
// std::vector<int>	Contiguous memory (all elements stored next to each other), Access: Supports random access via operator[] (O(1))
// std::deque<int>	Fast at both front and back, slower in the middle
// std::list<int>	No random access (operator[] not supported), must traverse with iterators
// std::forward_list<int> No random access, can only traverse forward
int main() {
    std::cout << "------ testing vector ------\n";
    std::vector<int> v = {1, 2, 4, 42, 100};
    test_container(v, 42);
    std::cout << "\n";

    std::cout << "------ testing deque ------\n";
    std::deque<int> d = {1, 2, 4, 42, 100};
    test_container(d, 42);
    std::cout << "\n";

    std::cout << "------ testing list ------\n";
    std::list<int> l = {1, 2, 4, 42, 100};
    test_container(l, 42);
    std::cout << "\n";

    std::cout << "------ forward_list vector ------\n";
    std::forward_list<int> f = {1, 2, 4, 42, 100};
    test_container(f, 0);
    std::cout << "\n";

    std::cout << "------ char vector ------\n";
    std::vector<char> g = {'a', 'b', 'c', 'd'};
    test_container(g, 99);
    std::cout << "\n";

    return 0;
}