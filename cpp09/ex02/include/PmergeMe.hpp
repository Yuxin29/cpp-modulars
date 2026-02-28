#pragma once

#include <vector>
#include <deque>
#include <ctime> // std::clock_t
#include <algorithm>    // std::lower_bound

// Ford-Johnson algorithm: Merge-Insertion Sort
// pairing, compairing, insertinh, recursion

// You must use at least two different containers (map, stack were used already)
// vector: dynamic array: ccontinous memory,            push_back
// deque: double ended queue: memory in small pieces    push_back/push_front, pop_back/pop_front,
class PmergeMe
{
private:
    std::vector<unsigned int>   _unsortedSequence;
    std::deque<unsigned int>    _sortedSequence;

    void        parsing(char **av);

    template <typename Container>
    void        processContainer(Container& c);
    
    public:
    PmergeMe(char **av){parsing(av);};
    ~ PmergeMe(){};

    void        sequenceSort();
};

template <typename Container>
void        PmergeMe::processContainer(Container& c){
    if (c.size() <= 1)
            return;

    Container winners;
    Container losers;

    for (size_t i = 0; i + 1 < c.size(); i += 2){
        if (c[i] > c[i + 1]){
            winners.push_back(c[i]);
            losers.push_back(c[i + 1]);
        }
        else
        {
            winners.push_back(c[i + 1]);
            losers.push_back(c[i]);
        }
    }
    if (c.size() % 2 == 1)
        winners.push_back(c.back());

    processContainer(winners);
    c = winners;

    for (size_t i = 0; i < losers.size(); i++){
        typename Container::iterator pos =std::lower_bound(c.begin(), c.end(), losers[i]);
        c.insert(pos, losers[i]);
    }
}