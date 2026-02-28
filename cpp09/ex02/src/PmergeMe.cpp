#include "PmergeMe.hpp"

#include <ctime>        // std::clock_t
#include <algorithm>    // std::lower_bound
#include <stdexcept>
#include <cstdlib>      // stoll
#include <cctype>       // std::isdigit
#include <climits>      // UINT_MAX
#include <string>
#include <iostream>

// =====================================================================================
// static local helper
static double   calculateTime(std::clock_t start, std::clock_t end){
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

static bool isPositiveInt(char *c, unsigned int &out){
    if (!c || !*c)
        return false;
    int i = 0;
    if (c[i] == '-')
        return false;
    else if (c[i] == '+')
        i++;
    if (!c[i])
        return false;
    for (; c[i]; i++){
        if (!std::isdigit(c[i]))
            return false;
    }
    long long value = std::strtoll(c, NULL, 10);
    if (value < 0 || value > UINT_MAX)
        return false;
    out = static_cast<unsigned int>(value);
    return true;
}

static void insertLosers(std::vector<unsigned int>& v, const std::vector<unsigned int>& losers){
    for (size_t i = 0; i < losers.size(); i++){
        std::vector<unsigned int>::iterator pos =
            std::lower_bound(v.begin(), v.end(), losers[i]);
        v.insert(pos, losers[i]);
    }
}

static void insertLosers(std::deque<unsigned int>& d, const std::deque<unsigned int>& losers){
    for (size_t i = 0; i < losers.size(); i++){
        std::deque<unsigned int>::iterator pos =
            std::lower_bound(d.begin(), d.end(), losers[i]);
        d.insert(pos, losers[i]);
    }
}

// =====================================================================================
//private helper
void    PmergeMe::parsing(char **av){
    if (!av[1])
       throw std::runtime_error("Error: no int arrays");
    for (int i = 1; av[i]; i++){
        unsigned int value;
        if (!isPositiveInt(av[i], value))
            throw std::runtime_error("Error");
        _vectorSequence.push_back(static_cast<unsigned int>(value));
        _dequeSequence.push_back(static_cast<unsigned int>(value));
    }
}

void PmergeMe::processVector(std::vector<unsigned int>& v){
    if (v.size() <= 1)
        return;

    std::vector<unsigned int> winners;
    std::vector<unsigned int> losers;
    for (size_t i = 0; i + 1 < v.size(); i += 2){
        if (v[i] > v[i + 1]){
            winners.push_back(v[i]);
            losers.push_back(v[i + 1]);
        }
        else{
            winners.push_back(v[i + 1]);
            losers.push_back(v[i]);
        }
    }

    if (v.size() % 2 == 1)
        winners.push_back(v.back());

    processVector(winners);
    v = winners;

    insertLosers(v, losers);
}

void PmergeMe::processDeque(std::deque<unsigned int>& d){
    if (d.size() <= 1)
        return;

    std::deque<unsigned int> winners;
    std::deque<unsigned int> losers;
    for (size_t i = 0; i + 1 < d.size(); i += 2){
        if (d[i] > d[i + 1]){
            winners.push_back(d[i]);
            losers.push_back(d[i + 1]);
        }
        else{
            winners.push_back(d[i + 1]);
            losers.push_back(d[i]);
        }
    }

    if (d.size() % 2 == 1)
        winners.push_back(d.back());

    processDeque(winners);
    d = winners;

    insertLosers(d, losers);
}

void PmergeMe::printBefore() const{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorSequence.size(); i++)
        std::cout << _vectorSequence[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printAfter() const{
    std::cout << "After: ";
    for (size_t i = 0; i < _dequeSequence.size(); i++)
        std::cout << _dequeSequence[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printTime(double t1, double t2) const{
    std::cout << "Time to process a range of " << _vectorSequence.size()
        << " elements with std::vector : " << t1 * 1e6 << " us" << std::endl;
    std::cout << "Time to process a range of " << _dequeSequence.size()
        << " elements with std::deque : " << t2 * 1e6 << " us" << std::endl;
}

// =====================================================================================
// public
void        PmergeMe::sequenceSort(){
    printBefore();

    //sort vector
    std::clock_t startVec = std::clock();
    processVector(_vectorSequence);
    std::clock_t endVec = std::clock();
    double timeVec = calculateTime(startVec, endVec);
    //sort deque
    std::clock_t startDeq = std::clock();
    processDeque(_dequeSequence);
    std::clock_t endDeq = std::clock();
    double timeDeq = calculateTime(startDeq, endDeq);

    printAfter();

    printTime(timeVec, timeDeq);
}
