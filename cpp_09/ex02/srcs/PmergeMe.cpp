#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
    (void) other;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this == &other)
        return *this;
    return *this;
}


void    PmergeMe::fordJohnsonVector(std::vector<int> &vector) {
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;

    pairComparisonVec(mainChain, pendChain, vector);
    mergeSortVec(mainChain, pendChain, 0, mainChain.size() -1);
    if (pendChain.size() > 0)
        insertVec(mainChain, pendChain);
    vector = mainChain;
}


void    PmergeMe::fordJohnsonDeque(std::deque<int> &deque) {
    std::deque<int> mainChain;
    std::deque<int> pendChain;

    pairComparisonDeq(mainChain, pendChain, deque);
    mergeSortDeq(mainChain, pendChain, 0, mainChain.size() - 1);
    if (pendChain.size() > 0)
        insertDeq(mainChain, pendChain);
    deque = mainChain;
}
