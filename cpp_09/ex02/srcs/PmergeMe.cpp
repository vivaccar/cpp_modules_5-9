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

void    PmergeMe::pairComparison(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &vector) {
    for (unsigned int i = 0; i < vector.size() - 1; i += 2)
    {
        if (vector[i] > vector[i + 1])
        {
            mainChain.push_back(vector[i]);
            pendChain.push_back(vector[i + 1]);
        }
        else
        {
            mainChain.push_back(vector[i + 1]);
            pendChain.push_back(vector[i]);
        }
    }
    if (vector.size() % 2 == 1)
        pendChain.push_back(vector[vector.size() - 1]);
}


void    PmergeMe::mergeVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int mid, int right) {
    std::vector<int> leftMain(mainChain.begin() + left, mainChain.begin() + mid + 1);
    std::vector<int> rightMain(mainChain.begin() + mid + 1, mainChain.begin() + right + 1);

    std::vector<int> leftPend(pendChain.begin() + left, pendChain.begin() + mid + 1);
    std::vector<int> rightPend(pendChain.begin() + mid + 1, pendChain.begin() + right + 1);

    std::vector<int>::iterator itMain = mainChain.begin() + left;
    std::vector<int>::iterator itPend = pendChain.begin() + left;
    std::vector<int>::iterator itLeftMain = leftMain.begin();
    std::vector<int>::iterator itRightMain = rightMain.begin();
    std::vector<int>::iterator itLeftPend = leftPend.begin();
    std::vector<int>::iterator itRightPend = rightPend.begin();

    while (itLeftMain != leftMain.end() && itRightMain != rightMain.end() && itLeftPend != leftPend.end() && itRightPend != rightPend.end())
    {
        if (*itLeftMain <= *itRightMain)
        {
            *itMain = *itLeftMain;
            *itPend = *itLeftPend;
            itLeftMain++;
            itLeftPend++;
        }
        else
        {
            *itMain = *itRightMain;
            *itPend = *itRightPend;
            itRightMain++;
            itRightPend++;
        }
        itMain++;
        itPend++;
    }

    while (itLeftMain != leftMain.end() && itLeftPend != leftPend.end())
    {
        *itMain = *itLeftMain;
        *itPend = *itLeftPend;
        itLeftMain++;
        itLeftPend++;
        itMain++;
        itPend++;
    }

    while (itRightMain != rightMain.end() && itRightPend != rightPend.end())
    {
        *itMain = *itRightMain;
        *itPend = *itRightPend;
        itRightMain++;
        itRightPend++;
        itMain++;
        itPend++;
    }
}

void    PmergeMe::mergeSortVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int right) {
    if (left >= right)
        return ;
    int mid = left + (right - left) / 2;
    mergeSortVec(mainChain, pendChain, left, mid);
    mergeSortVec(mainChain, pendChain, mid + 1, right);
    mergeVec(mainChain, pendChain, left, mid, right);
}

void    PmergeMe::fordJohnsonVector(std::vector<int> &vector) {
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;

    pairComparison(mainChain, pendChain, vector);
    std::cout << "MAIN CHAIN: ";
    printVec(mainChain);

    std::cout << "pend CHAIN: ";
    printVec(pendChain);

    mergeSortVec(mainChain, pendChain, 0, mainChain.size() -1);

    std::cout << "\nAFTER\n";
    std::cout << "MAIN CHAIN: ";
    printVec(mainChain);

    std::cout << "pend CHAIN: ";
    printVec(pendChain);
}

void    PmergeMe::printVec(std::vector<int> &vector) {
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
