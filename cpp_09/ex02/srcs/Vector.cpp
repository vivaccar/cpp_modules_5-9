#include "../includes/PmergeMe.hpp"

void    pairComparisonVec(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &vector) {
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


void mergeVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int mid, int right) {
    // subvectors
    std::vector<int> leftMain(mainChain.begin() + left, mainChain.begin() + mid + 1);
    std::vector<int> rightMain(mainChain.begin() + mid + 1, mainChain.begin() + right + 1);

    std::vector<int> leftPend(pendChain.begin() + left, pendChain.begin() + mid + 1);
    std::vector<int> rightPend(pendChain.begin() + mid + 1, pendChain.begin() + right + 1);

    size_t mainIdx = left;
    size_t leftIdx = 0, rightIdx = 0;

    while (leftIdx < leftMain.size() && rightIdx < rightMain.size())
    {
        if (leftMain[leftIdx] <= rightMain[rightIdx])
        {
            mainChain[mainIdx] = leftMain[leftIdx];
            pendChain[mainIdx] = leftPend[leftIdx];
            leftIdx++;
        }
        else
        {
            mainChain[mainIdx] = rightMain[rightIdx];
            pendChain[mainIdx] = rightPend[rightIdx];
            rightIdx++;
        }
        mainIdx++;
    }

    // Copyremaining elements from the left side
    while (leftIdx < leftMain.size())
    {
        mainChain[mainIdx] = leftMain[leftIdx];
        pendChain[mainIdx] = leftPend[leftIdx];
        leftIdx++;
        mainIdx++;
    }

    // Copyremaining elements from the right side
    while (rightIdx < rightMain.size())
    {
        mainChain[mainIdx] = rightMain[rightIdx];
        pendChain[mainIdx] = rightPend[rightIdx];
        rightIdx++;
        mainIdx++;
    }
}

void    mergeSortVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int right) {
    if (left >= right)
        return ;
    int mid = left + (right - left) / 2;
    mergeSortVec(mainChain, pendChain, left, mid);
    mergeSortVec(mainChain, pendChain, mid + 1, right);
    mergeVec(mainChain, pendChain, left, mid, right);
}

std::vector<int>    JacobsthalVec(size_t size)
{
    std::vector<int> jacobSequence;

    int j_m1 = 2;
    int j_m2 = 2;
    size_t counter = 0;

    while (counter < size)
    {
        if (counter == 0)
        {
            jacobSequence.push_back(2);
            counter = std::accumulate(jacobSequence.begin(), jacobSequence.end(), 0);
        }
        else if (counter == 2)
        {
            jacobSequence.push_back(2);
            counter = std::accumulate(jacobSequence.begin(), jacobSequence.end(), 0);
        }
        else
        {
            int jacobstahl = j_m1 + 2 * j_m2;
            j_m2 = j_m1;
            j_m1 = jacobstahl;
            jacobSequence.push_back(jacobstahl);
            counter = std::accumulate(jacobSequence.begin(), jacobSequence.end(), 0);
        }
    }
    return jacobSequence;
}

void binaryInsertVec(std::vector<int> &vec, int value, int size)
{
    if (static_cast<int>(vec.size()) < size)
        size = static_cast<int>(vec.size());

    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    vec.insert(vec.begin() + left, value);
}

void insertion(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> jacobSequence)
{
    std::vector<int>::iterator pendIt = pendChain.begin();
    int groupIdx = 1;
    for (std::vector<int>::iterator jacobIt = jacobSequence.begin(); jacobIt != jacobSequence.end(); jacobIt++)
    {
        int nbrsLeft = std::distance(pendIt, pendChain.end());
        int size = *jacobIt;
        if (nbrsLeft < size)
            size = nbrsLeft;
        std::vector<int> group(pendIt, pendIt + size);
        int mainLenght = std::pow(2, groupIdx + 1) - 1;
        for (std::vector<int>::iterator insertionIt = group.end() - 1; insertionIt != group.begin(); insertionIt--)
            binaryInsertVec(mainChain, *insertionIt, mainLenght);
        binaryInsertVec(mainChain, *group.begin(), mainLenght);
        pendIt += size;
        groupIdx++;
    }
}

/* 
        // INSERTION SEQUENCE DEMOSTRATION
        
        std::cout << "\n\n";
        std::cout << "NEXT GROUP WILL BE INSERTED:\nJacob number(GROUP SIZE) --> " << *jacobIt << std::endl;
        std::cout << "MAIN CHAIN--> ";
        printVec(mainChain);
        std::cout << "\nPEND CHAIN-->";
        printVec(pendChain);
        std::cout << "\nGROUP TO INSERT --> ";
        printVec(group);
        std::cout << "\nGROUP size--> " << size << std::endl;
        std::cout << "Main size to find " << mainLenght << std::endl;
        printVec(mainChain);
        
 */



void    insertVec(std::vector<int> &mainChain, std::vector<int> &pendChain) {
    
    mainChain.insert(mainChain.begin(), pendChain[0]);
    pendChain.erase(pendChain.begin());
    
    if (pendChain.size() == 0)
        return ;
    std::vector<int> jacobSequence = JacobsthalVec(pendChain.size());
    insertion(mainChain, pendChain, jacobSequence);
}

void    printVec(std::vector<int> &vector) {
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
