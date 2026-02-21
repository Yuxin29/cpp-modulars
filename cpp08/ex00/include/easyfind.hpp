#pragma once

#include <algorithm>    //std::find
#include <stdexcept>    //except, <type_traits>。

// STL (Standard Template Library)
// Containers: These store data. Examples include: vector, list, map set
// Algorithms: These perform operations on containers. Examples: sort(), find(), count(), transform()
// Iterators:

// associative/ Unordered containers : Associative containers store and manage elements using keys, rather than positions.
// - Elements are accessed by key
// - There is no concept of “nth element”
// - Traversal order is not the insertion order
// Some are automatically sorted by key, others are completely unordered
// -Keys are usually unique (depending on the container)
// Examples:
// std::map                                     sorted by key   
// std::unordered_map / std::unordered_set      hash-based, unordered
// std::set                                     only key, automatecately ordered

// ordered/sequence containers: Sequence containers store elements in a linear order, where each element has a well-defined position relative to the others.
// - Elements are stored in insertion order
// - Each element has a specific position (first, second, etc.)
// - Duplicate elements are allowed
// - Elements are accessed by position, not by key
// - Support sequential traversal using iterators (begin() / end())
// Examples:
// std::vector<int>         Contiguous memory (all elements stored next to each other), Access: Supports random access via operator[] (O(1))
// std::deque<int>          Fast at both front and back, slower in the middle
// std::list<int>	        No random access (operator[] not supported), must traverse with iterators
// std::forward_list<int>   No random access, can only traverse forward

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    // if (!std::is_same_v<typename T::value_type, int>)
    //     throw std::runtime_error("Only int container supported");
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}
