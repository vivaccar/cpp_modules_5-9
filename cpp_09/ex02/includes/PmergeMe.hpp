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
#include <numeric>


class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        static void    printVec(std::vector<int> &vector);
        static void    fordJohnsonVector(std::vector<int> &vector);
        static void    pairComparison(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &vector);
        static void    mergeSortVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int right);
        static void    mergeVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int mid, int right);
        static std::vector<int>    &insertVec(std::vector<int> &mainChain, std::vector<int> &pendChain);
};


#endif