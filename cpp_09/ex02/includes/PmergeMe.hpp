#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <numeric>
#include <cmath>
#include <algorithm>


class PmergeMe
{   
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        static void    fordJohnsonVector(std::vector<int> &vector);
        static void    fordJohnsonDeque(std::deque<int> &deque);
        
};

void    printVec(std::vector<int> &vector);
void    pairComparisonVec(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &vector);
void    mergeSortVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int right);
void    mergeVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int mid, int right);
void    insertVec(std::vector<int> &mainChain, std::vector<int> &pendChain);

void    printDeq(std::deque<int> &deque);
void    pairComparisonDeq(std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &deque);
void    mergeSortDeq(std::deque<int> &mainChain, std::deque<int> &pendChain, int left, int right);
void    mergeDeq(std::deque<int> &mainChain, std::deque<int> &pendChain, int left, int mid, int right);
void    insertDeq(std::deque<int> &mainChain, std::deque<int> &pendChain);



#endif