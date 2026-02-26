#include "PmergeMe.hpp"

#include <stdexcept>
#include <iostream>
#include <cstdlib> // stoll
#include <cctype>  // std::isdigit
#include <climits> // UINT_MAX

//private helper
void    PmergeMe::parsing(char **av){
    if (!av[1])
       throw std::runtime_error("Error: no int arrays");
    for (int i = 1; av[i]; i++){
        for (int j = 0; av[i][j]; j++)
            if (!std::isdigit(av[i][j]))
                throw std::runtime_error("Error: invald nbr");
        long long nbr = std::atoll(av[i]);
        if (nbr < 0 || nbr > UINT_MAX)
            throw std::runtime_error("Error: invald int");
        _unsortedSequence.push_back(static_cast<unsigned int>(nbr));
        _sortedSequence.push_back(static_cast<unsigned int>(nbr));
    }
}

void    PmergeMe::processVector(std::vector<unsigned int>& v){
    if (v.size() <= 1)
        return;

    std::vector<unsigned int> biggers;
    std::vector<unsigned int> smallers;

    // pairing
    // separate winners and losers
    for (size_t i = 0; i + 1 < v.size(); i += 2){
        if (v[i] > v[i + 1]){
            //ss
        }
        else{
            //ss
        }
    }

    // recursive sort winners

    // binary insert losers

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
         std::cout << v[i] << " ";
    std::cout << std::endl;
    //Time to process a range of X elements with std::vector : ...
}

void    PmergeMe::processDeque(std::deque<unsigned int>& d){
    if (d.size() <= 1)
        return;
        
    std::cout << "After: ";
    for (size_t i = 0; i < d.size(); i++)
         std::cout << d[i] << " ";
    std::cout << std::endl;
    //Time to process a range of X elements with std::deque : ...
}

PmergeMe::PmergeMe(char **av){
    parsing(av);
}
    
PmergeMe::~ PmergeMe(){
}

void        PmergeMe::sequenceSort(){
    processVector(_unsortedSequence);
    processDeque(_sortedSequence);
}


