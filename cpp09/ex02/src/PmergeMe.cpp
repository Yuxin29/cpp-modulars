#include "PmergeMe.hpp"

#include <stdexcept>
#include <iostream>
#include <cstdlib> // stoll
#include <climits> //UINI_MAX

//private helper
void        PmergeMe::parsing(char **av){
    for (int i = 1; av[i]; i++){
        long long nbr = std::atoll(av[i]);
        if (nbr < 0 || nbr > UINT_MAX)
            throw std::runtime_error("invald int");
        _unsortedSequence.push_back(static_cast<unsigned int>(nbr));
        _sortedSequence.push_back(static_cast<unsigned int>(nbr));
    }
}

void        PmergeMe::processVector(){
    if (_unsortedSequence.size() <= 1)
        return;

    // pairing
    // separate winners and losers
    // recursive sort winners
    // binary insert losers

    //std::cout << _unsortedSequence << std::endl;
}

void        PmergeMe::processDeque(){
    //std::cout << _unsortedSequence << std::endl;
}

PmergeMe::PmergeMe(char **av){
    parsing(av);
}
    
PmergeMe::~ PmergeMe(){
}

void        PmergeMe::sequenceSort(){
    processVector();
    processDeque();
}


