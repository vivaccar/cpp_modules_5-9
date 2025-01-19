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



void    PmergeMe::printDeque(std::deque<int> &deque) {
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    {
        std::cout << *it;
        if (it + 1 != deque.end())
            std::cout << " ";
        else
            std::cout << std::endl;
    }
}