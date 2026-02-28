#include "PmergeMe.hpp"
#include <chrono>    
#include <algorithm>    // std::lower_bound
#include <stdexcept>
#include <cstdlib>      // stoll
#include <cctype>       // std::isdigit
#include <climits>      // UINT_MAX

// static local utils
namespace pm_utils
{
    bool    isPositiveInt(char *c, unsigned int &value){
        int i = 0;
        if (!c || !*c)
            return false;
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
        long long nbr = std::strtoll(c, NULL, 10);
        if (nbr < 0 || nbr > UINT_MAX)
            return false;
        value = static_cast<unsigned int>(nbr);
        return true;
    }

    void    insertLosers(std::vector<unsigned int>& v, const std::vector<unsigned int>& losers){
        std::vector<unsigned int> merged;
        merged.reserve(v.size() + losers.size());
        std::merge(v.begin(), v.end(), losers.begin(), losers.end(), std::back_inserter(merged));
        v.swap(merged);
    }

    void    insertLosers(std::deque<unsigned int>& d,const std::deque<unsigned int>& losers){
        std::deque<unsigned int> merged;
        merged.resize(0);           // or just declare empty
        merged.clear();
        std::merge(d.begin(), d.end(), losers.begin(), losers.end(), std::back_inserter(merged));
        d.swap(merged);
    }
}

//private helper
void    PmergeMe::parsing(char **av){
    if (!av[1])
       throw std::runtime_error("Error: no int arrays");
    for (int i = 1; av[i]; i++){
        unsigned int value;
        if (!pm_utils::isPositiveInt(av[i], value))
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
    v.swap(winners);
    pm_utils::insertLosers(v, losers);
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
    d.swap(winners);
    pm_utils::insertLosers(d, losers);
}

void PmergeMe::printNbr(const char* prefix) const{
    std::cout << prefix << ": ";
    for (size_t i = 0; i < _vectorSequence.size(); i++)
        std::cout << _vectorSequence[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printTime(double t1, double t2) const{
    size_t total = _vectorSequence.size();
    std::cout << "Time to process a range of " << total << " elements with std::vector : " << t1 << " us\n";
    std::cout << "Time to process a range of " << total << " elements with std::deque : " << t2 << " us\n";
}

// public
void        PmergeMe::sequenceSort(){
    printNbr("Before");
    // ------------- sort vector -------------
    std::chrono::high_resolution_clock::time_point startVec = std::chrono::high_resolution_clock::now();
    processVector(_vectorSequence);
    std::chrono::high_resolution_clock::time_point endVec = std::chrono::high_resolution_clock::now();
    double timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count();
    // ------------- sort deque -------------
    std::chrono::high_resolution_clock::time_point startDeq = std::chrono::high_resolution_clock::now();
    processDeque(_dequeSequence);
    std::chrono::high_resolution_clock::time_point endDeq = std::chrono::high_resolution_clock::now();
    double timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();
    printNbr("After");
    printTime(timeVec, timeDeq);
}
