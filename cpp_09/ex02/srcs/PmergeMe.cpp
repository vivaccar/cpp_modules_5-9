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


void PmergeMe::mergeVec(std::vector<int> &mainChain, std::vector<int> &pendChain, int left, int mid, int right) {
    // Criar subvetores
    std::vector<int> leftMain(mainChain.begin() + left, mainChain.begin() + mid + 1);
    std::vector<int> rightMain(mainChain.begin() + mid + 1, mainChain.begin() + right + 1);

    std::vector<int> leftPend(pendChain.begin() + left, pendChain.begin() + mid + 1);
    std::vector<int> rightPend(pendChain.begin() + mid + 1, pendChain.begin() + right + 1);

    // Iteradores para percorrer os subvetores e o vetor principal
    size_t mainIdx = left;
    size_t leftIdx = 0, rightIdx = 0;

    // Mesclar os subvetores enquanto houver elementos em ambos
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

    // Copiar os elementos restantes do lado esquerdo
    while (leftIdx < leftMain.size())
    {
        mainChain[mainIdx] = leftMain[leftIdx];
        pendChain[mainIdx] = leftPend[leftIdx];
        leftIdx++;
        mainIdx++;
    }

    // Copiar os elementos restantes do lado direito
    while (rightIdx < rightMain.size())
    {
        mainChain[mainIdx] = rightMain[rightIdx];
        pendChain[mainIdx] = rightPend[rightIdx];
        rightIdx++;
        mainIdx++;
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

std::vector<int>    Jacobsthal(size_t size)
{
    std::vector<int> jacobSequence;

    int j_m1 = 2;
    int j_m2 = 2;
    size_t counter = 0;

    if (size >= 2)
    {
        jacobSequence.push_back(j_m1);
        if (size >= 4)
            jacobSequence.push_back(j_m2);
    }
    counter = std::accumulate(jacobSequence.begin(), jacobSequence.end(), 0);
    std::cout << counter << std::endl;
    
    return jacobSequence;
}

std::vector<int>    &PmergeMe::insertVec(std::vector<int> &mainChain, std::vector<int> &pendChain) {
    
    std::vector<int> &sortedVector(mainChain);
    (void) pendChain;

    // insiro o primeiro elemento de pend no inicio de mainChain
    sortedVector.insert(sortedVector.begin(), pendChain[0]);
    pendChain.erase(pendChain.begin());
    
    std::vector<int> jacobSequence = Jacobsthal(pendChain.size());
    
    printVec(jacobSequence);
    printVec(pendChain);
    printVec(sortedVector);
    return sortedVector;
}

void    PmergeMe::fordJohnsonVector(std::vector<int> &vector) {
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;

    pairComparison(mainChain, pendChain, vector);
    std::cout << "MAIN CHAIN: ";
    printVec(mainChain);

    std::cout << "PEND CHAIN: ";
    printVec(pendChain);

    mergeSortVec(mainChain, pendChain, 0, mainChain.size() -1);

    std::cout << "\nAFTER\n";
    std::cout << "MAIN CHAIN: ";
    printVec(mainChain);

    std::cout << "PEND CHAIN: ";
    printVec(pendChain);


    vector = insertVec(mainChain, pendChain);
}

void    PmergeMe::printVec(std::vector<int> &vector) {
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
