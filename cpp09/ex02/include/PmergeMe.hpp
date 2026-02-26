#pragma once

#include <string>
#include <vector>
#include <deque>

// Ford-Johnson algorithm: Merge-Insertion Sort
// pairing, compairing, insertinh, recursion

// You must use at least two different containers (map, stack were used already)
// vector: dynamic array: ccontinous memory,            push_back
// deque: double ended queue: memory in small pieces    push_back/push_front, pop_back/pop_front,
// Your program must be able to handle at least 3000 different integers.
class PmergeMe
{
private:
    std::vector<unsigned int>   _unsortedSequence;
    std::deque<unsigned int>    _sortedSequence;

    void        parsing(char **av);
    void        processVector();
    void        processDeque();

public:
    PmergeMe(char **av);
    ~ PmergeMe();

    void        sequenceSort();
};

