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
};


#endif