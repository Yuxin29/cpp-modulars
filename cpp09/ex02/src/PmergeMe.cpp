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
    processVector(biggers);
    v = biggers;

    // binary insert losers
    // ,,,
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

void    PmergeMe::printVector(const std::vector<unsigned int>& v){
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
         std::cout << v[i] << " ";
    std::cout << std::endl;
}

void    PmergeMe::printDeque(const std::deque<unsigned int>& d){
    std::cout << "After";
    for (size_t i = 0; i < d.size(); i++)
         std::cout << d[i] << " ";
    std::cout << std::endl;
}

double      PmergeMe::calculateTime(std::clock_t start, std::clock_t end) const{
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

// public
void        PmergeMe::sequenceSort(){
    //sort vector
    std::clock_t startVec = std::clock();
    processVector(_unsortedSequence);
    std::clock_t endVec = std::clock();
    double timeVec = calculateTime(startVec, endVec);

    //print result and time of vector
    printVector(_unsortedSequence);
    std::cout << "Time to process a range of " << _unsortedSequence.size() << " elements with std::vector : " 
                << timeVec * 1e6 << " us" << std::endl;

    //sort deque
    std::clock_t startDeq = std::clock();
    processDeque(_sortedSequence);
    std::clock_t endDeq = std::clock();
    double timeDeq = calculateTime(startDeq, endDeq);
    
    // print result and time of deque
    printDeque(_sortedSequence);
    std::cout << "Time to process a range of " << _sortedSequence.size() << " elements with std::deque : " 
                << timeDeq * 1e6 << " us" << std::endl;
}
