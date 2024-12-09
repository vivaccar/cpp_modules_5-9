#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>

class PmergeMe {

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &other);

        static void mergeMe(std::vector<int> &vector);
        static void        mergeInsertionSort(std::vector<int>& vector, size_t left, size_t right);
        static void        merge(std::vector<int>& vector, size_t left, size_t mid, size_t right);
        
        static void printVector(std::vector<int> &vector);
        static void printDeque(std::deque<int> &deque);
};

#endif