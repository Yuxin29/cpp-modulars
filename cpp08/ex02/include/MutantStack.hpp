#pragma once

#include <string>
#include <iostream>
#include <stack> //rand

// std::stack    container adapter   first in, last out
// by default, std::stack use deque internally to storage data
// it supports: push(), pop(), top(), empty(), size()
// it deos not support: iterator
// it uses container c at the base level, we do use by inherite
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    using container_type = typename std::stack<T>::container_type;
    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;

    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }

    const_iterator begin() const {
        return this->c.begin();
    }
        
    const_iterator end() const {
        return this->c.end();
    }
};