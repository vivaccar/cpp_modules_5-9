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
    private:
        std::vector<int> mainChain;
        std::vector<int> pendChain;
    
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &other);

        void    fordJohnsonVec(std::vector<int> &vector);
        void    sortPairs(std::vector<int> &vector);

        static void         printVector(std::vector<int> &vector);
        static void         printDeque(std::deque<int> &deque);
};

#endif