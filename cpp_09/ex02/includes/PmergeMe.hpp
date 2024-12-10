#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <ctime>

class PmergeMe {

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &other);

        static void        mergeMeVec(std::vector<int> &vector);
        static void        mergeInsertionSortVec(std::vector<int>& vector, size_t left, size_t right);
        static void        mergeVec(std::vector<int>& vector, size_t left, size_t mid, size_t right);

        static void        mergeMeDeq(std::deque<int> &deque);
        static void        mergeInsertionSortDeq(std::deque<int>& deque, size_t left, size_t right);
        static void        mergeDeq(std::deque<int>& deque, size_t left, size_t mid, size_t right);
        
        static void         printVector(std::vector<int> &vector);
        static void         printDeque(std::deque<int> &deque);
};

#endif