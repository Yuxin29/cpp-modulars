#include "PmergeMe.hpp"

#include <chrono>    
#include <algorithm>    // std::lower_bound
#include <stdexcept>
#include <cstdlib>      // stoll
#include <cctype>       // std::isdigit
#include <climits>      // UINT_MAX

/**
* @brief 	Validate if the input string is a positive integer and convert it to unsigned int
* @param 	c the input string to validate and convert
* @param 	value the reference to store the converted unsigned int value
* @return 	true if the input string is a valid positive integer and the conversion is successful, false otherwise

* @rules    Your program must be able to use a positive integer sequence as an argument
*/
static bool    isPositiveInt(char *c, unsigned int &value){
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

/**
* @brief 	print the sequence of unsigned integers with a prefix message
* @param 	prefix the prefix message to print: "Before: , "After: "
* @param 	v the vector of unsigned integers to print
* @return 	void
*/
static void printNbr(const char* prefix, const std::vector<unsigned int>& v){
    std::cout << prefix;
    for (size_t i = 0; i < v.size(); i++){
        std::cout << v[i];
        if (i + 1 < v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

/**
* @brief 	generate the Jacob order for inserting losers into winners
* @param 	n the number of losers to insert
* @return 	a vector of indices representing the Jacob order
*
* @note 	The Jacob order is generated based on the Jacob sequence, which is defined as:
            J(0) = 0
            J(1) = 1
            J(n) = J(n-1) + 2 * J(n-2) for n > 1
            The Jacob order is then derived from the Jacob sequence by taking all indices i where J(i) < n, in reverse order.   
*/
template <typename SizeContainer>
static SizeContainer generateJacobOrder(size_t n){
    SizeContainer order;
    if (n == 0)
        return order;
    SizeContainer jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n){
        size_t sz = jac.size();
        jac.push_back(jac[sz - 1] + 2 * jac[sz - 2]);
    }
    for (size_t i = jac.size(); i-- > 0;){
        if (jac[i] < n)
            order.push_back(jac[i]);
    }
    return order;
}

/**
* @brief 	Insert the losers into the winners according to the Jacob order
* @param 	winners the container of winners to insert into
* @param 	losers the container of losers to be inserted   
* @return 	void
*/
template <typename Container>
static void insertJacob(Container& winners, const Container& losers){
    using SizeContainer = std::vector<size_t>;
    SizeContainer order = generateJacobOrder<SizeContainer>(losers.size());
    std::vector<bool> inserted(losers.size(), false);
    for (size_t idx : order){
        if (idx < losers.size() && !inserted[idx]){
            winners.insert(std::lower_bound(winners.begin(), winners.end(), losers[idx]),losers[idx]);
            inserted[idx] = true;
        }
    }
    for (size_t i = 0; i < losers.size(); ++i){
        if (!inserted[i])
            winners.insert(std::lower_bound(winners.begin(), winners.end(), losers[i]),losers[i]);
    }
}

/**
* @brief 	Parse the input arguments, validate them, and fill the vector and deque sequences
* @param 	av the input arguments from the command line
* @return 	void, throw runtime_error if any argument is invalid    
*
*/
void    PmergeMe::parsing(char **av){
    for (int i = 1; av[i]; i++){
        unsigned int value;
        if (!isPositiveInt(av[i], value))
            throw std::runtime_error("Error");
        _vectorSequence.push_back(static_cast<unsigned int>(value));
        _dequeSequence.push_back(static_cast<unsigned int>(value));
    }
}

/**
* @brief 	Process the vector sequence
* @param 	v the vector to process
* @return 	void
*
* @note 	It is strongly advised to implement your algorithm for each container and thus to avoid using a generic function.
*        
* @note 	recursive base case: if the vector has 0 or 1 element, it's already sorted
*/
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
    insertJacob(winners, losers);
    v.swap(winners);
}

/**
* @brief 	Process the deque sequence
* @param 	d the deque to process
* @return 	void
*
* @note 	Same algorithm as vector, but implemented separately to avoid using a generic function.
* 
*/
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
    insertJacob(winners, losers);
    d.swap(winners);
}

void PmergeMe::printTime(double t1, double t2) const{
    size_t total = _vectorSequence.size();
    std::cout << "Time to process a range of " << total << " elements with std::vector : " << t1 << " us\n";
    std::cout << "Time to process a range of " << total << " elements with std::deque : " << t2 << " us\n";
}

/**
* @brief 	main function to sort the sequences and print the results
* @param 	void
* @return 	void
* @throw 	runtime_error if any error occurs during sorting
* 
* @note 	the time used to perform all your operations, both the sorting part and the data management part.
* @note     why we need to copy the original sequences before sorting: 
            - Ensure fair timing comparison between vector and deque
            - Keep the original input unchanged
            - Avoid modifying the original containers
*/
void        PmergeMe::sequenceSort(){
    printNbr("Before: ", _vectorSequence);
    // ------------- sort vector -------------
    auto startVec = std::chrono::high_resolution_clock::now();
    std::vector<unsigned int> vecCopy = _vectorSequence;
    processVector(vecCopy);
    auto endVec = std::chrono::high_resolution_clock::now();
    double timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count ();
    // ------------- sort deque -------------
    auto startDeq = std::chrono::high_resolution_clock::now();
    std::deque<unsigned int> deqCopy = _dequeSequence;
    processDeque(deqCopy);
    auto endDeq = std::chrono::high_resolution_clock::now();
    double timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();
    printNbr("After: ", vecCopy);
    printTime(timeVec, timeDeq);
}
