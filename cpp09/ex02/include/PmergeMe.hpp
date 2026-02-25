#pragma once

#include <string>
#include <vector>

// Ford-Johnson algorithm.
// pairing, pairing of pairs, recursion

// maybe vector and sorted map ? 
// You must use at least two different containers (map, stack were used already)
// Your program must be able to handle at least 3000 different integers.
class PmergeMe
{
private:
    std::vector<unsigned int> _unsortedSequence;
    std::vector<unsigned int> _sortedSequence;

    void        isValidSequence (const std::string &av);

public:
    PmergeMe();
    ~ PmergeMe();

    void        sequenceSort(const std::string _sequence);
};

