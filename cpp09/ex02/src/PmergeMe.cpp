#include "PmergeMe.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

//private helper
void        PmergeMe::parsing(const std::string **av){
    for (int i = 1; av[i]; i++){
        long long nbr = std::atoll(av[i]);
        if (nbr < 0 || nbr > UINT_MAX)
            throw std::runtime_error("invald int");
        _unsortedSequence.push_back(static_cast<int>(nbr));
        _sortedSequence.push_back(static_cast<int>(nbr));
    }
}

void        PmergeMe::processVector(){
    if (_unsortedSequence.size() <= 1)
        return;

    // pairing
    // separate winners and losers
    // recursive sort winners
    // binary insert losers
}

void        PmergeMe::processDeque(){

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


