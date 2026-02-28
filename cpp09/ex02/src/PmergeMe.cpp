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

static void    printVector(const std::vector<unsigned int>& v){
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
         std::cout << v[i] << " ";
    std::cout << std::endl;
}

static void    printDeque(const std::deque<unsigned int>& d){
    std::cout << "After: ";
    for (size_t i = 0; i < d.size(); i++)
         std::cout << d[i] << " ";
    std::cout << std::endl;
}

static double      calculateTime(std::clock_t start, std::clock_t end){
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

// public
void        PmergeMe::sequenceSort(){
    //sort vector
    std::clock_t startVec = std::clock();
    processContainer(_unsortedSequence);
    std::clock_t endVec = std::clock();
    double timeVec = calculateTime(startVec, endVec);

    //sort deque
    std::clock_t startDeq = std::clock();
    processContainer(_sortedSequence);
    std::clock_t endDeq = std::clock();
    double timeDeq = calculateTime(startDeq, endDeq);
    
    printVector(_unsortedSequence);
    printDeque(_sortedSequence);
    
    std::cout << "Time to process a range of " << _unsortedSequence.size() << " elements with std::vector : " 
                << timeVec * 1e6 << " us" << std::endl;
    std::cout << "Time to process a range of " << _sortedSequence.size() << " elements with std::deque : " 
                << timeDeq * 1e6 << " us" << std::endl;
}
