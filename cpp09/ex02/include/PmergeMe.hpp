#pragma once

#include <string>
#include <vector>
#include <deque>

// Ford-Johnson algorithm: Merge-Insertion Sort
// pairing, compairing, insertinh, recursion

// maybe vector and sorted map ? 
// You must use at least two different containers (map, stack were used already)
// Your program must be able to handle at least 3000 different integers.
class PmergeMe
{
private:
    std::vector<unsigned int>   _unsortedSequence;
    std::deque<unsigned int>    _sortedSequence;

    void        parsing(const std::string**av);
    void        processVector();
    void        processDeque();

public:
    PmergeMe(char **av);
    ~ PmergeMe();

    void        sequenceSort();
};

