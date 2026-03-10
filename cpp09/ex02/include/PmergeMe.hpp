#pragma once

#include <vector>
#include <deque>
#include <iostream>

/**
* @brief 	A class to sort a sequence of positive integers using the Ford-Johnson algorithm (Merge-Insertion Sort)
*
* @Notes    Ford-Johnson algorithm: Merge-Insertion Sort: pairing, compairing, insertinh, recursion
* @Why      vector: dynamic array: continous memory                 push_back
//          deque: double ended queue: memory in small pieces       push_back/push_front, pop_back/pop_front,
*/
class PmergeMe
{
private:
    //You must use at least two different containers in your code to validate this exercise. Your program must be able to handle at least 3000 different integers.
    // It is strongly advised to implement your algorithm for each containerand thus to avoid using a generic function.
    std::vector<unsigned int>   _vectorSequence;
    std::deque<unsigned int>    _dequeSequence;

    void    parsing(char **av);
    void    processVector(std::vector<unsigned int>& v);
    void    processDeque(std::deque<unsigned int>& d);
    void    printTime(double t1, double t2) const;

public:
    PmergeMe(char **av){parsing(av);};
    ~ PmergeMe(){};

    void        sequenceSort();
};