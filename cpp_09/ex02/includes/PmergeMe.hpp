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
private:
    T mainChain;
    T pendChain;


public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void merge(int left, int mid, int right);
    void binaryInsert(int left, int right, int number);
    void mergeSort(int left, int right);
    void insert(void);

    int getSizeMain() const;

};


#endif