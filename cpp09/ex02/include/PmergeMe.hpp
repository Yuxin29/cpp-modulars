#pragma once

#include <vector>
#include <deque>
#include <iostream>

// Ford-Johnson algorithm: Merge-Insertion Sort: pairing, compairing, insertinh, recursion
// You must use at least two different containers (map, stack were used already)
// vector: dynamic array: continous memory,            push_back
// deque: double ended queue: memory in small pieces    push_back/push_front, pop_back/pop_front,
class PmergeMe
{
private:
    std::vector<unsigned int>   _vectorSequence;
    std::deque<unsigned int>    _dequeSequence;

    void    parsing(char **av);
    void    processVector(std::vector<unsigned int>& v);
    void    processDeque(std::deque<unsigned int>& d);
    void    printNbr(const char* prefix) const;
    void    printTime(double t1, double t2) const;

public:
    PmergeMe(char **av){parsing(av);};
    ~ PmergeMe(){};

    void        sequenceSort();
};