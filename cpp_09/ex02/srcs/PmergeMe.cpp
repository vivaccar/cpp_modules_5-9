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


void binaryInsert(std::vector<int>& vec, int value) {
    std::vector<int>::iterator low = vec.begin();
    std::vector<int>::iterator high = vec.end();

    // Busca binária para encontrar a posição correta de inserção
    while (low < high) 
    {
        std::vector<int>::iterator mid = low + (high - low) / 2;
        if (*mid < value)
            low = mid + 1;
        else
            high = mid;
    }

    // Insere o elemento na posição correta
    vec.insert(low, value);
}



std::vector<std::pair<int, std::vector<int>::iterator> >  createInsertionSeq(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> jacobSequence)
{
    std::vector<std::pair<int, std::vector<int>::iterator> > pairs;
    std::vector<int>::iterator mBegin = mainChain.begin();
    std::vector<int>::iterator pBegin = pendChain.begin();
    (void) jacobSequence;
    
    mBegin += 2;
    while (pBegin != pendChain.end())
    {
        
        pairs.push_back(std::make_pair(*pBegin, mBegin));
        mBegin++;
        if (mBegin == mainChain.end())
            break;
        pBegin++;
    }
    
    std::cout << "MAIN CHAIN: ";
    PmergeMe::printVec(mainChain);
    std::cout << "\npend CHAIN: ";

    PmergeMe::printVec(pendChain);

    //TEST PAIRS
    for (std::vector<std::pair<int, std::vector<int>::iterator> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        std::cout << it->first << " is pointing to -> " << *it->second << std::endl; 
    
    for (std::vector<int>::iterator it = jacobSequence.begin(); it != jacobSequence.end(); it++)
    {
        int nbrsToInsert = *it;
        while (nbrsToInsert > 0)
        {
            std::vector<int> insertionVector
        }
    }
    std::vector<std::pair<int, std::vector<int>::iterator> >::iterator it = pairs.begin();
    std::vector<int> subVector(mainChain.begin(), it->second);
    PmergeMe::printVec(subVector);
    binaryInsert(subVector, it->first);
    PmergeMe::printVec(subVector);
    return pairs;
}

std::vector<int>    &PmergeMe::insertVec(std::vector<int> &mainChain, std::vector<int> &pendChain) {
    
    std::vector<int> &sortedVector(mainChain);

    // insiro o primeiro elemento de pend no inicio de mainChain
    sortedVector.insert(sortedVector.begin(), pendChain[0]);
    pendChain.erase(pendChain.begin());
    
    if (pendChain.size() == 0)
        return sortedVector;
    std::vector<int> jacobSequence = Jacobsthal(pendChain.size());
    //std::cout << "AFTER JACOB SEQUENCE CREATED";
    //std::cout << "JACOBS:";
    // FAZER PARES DOS ITENS DA PEND COM ITERADORES PARA SEU PAR NA MAIN;
    std::vector<std::pair<int, std::vector<int>::iterator> > pairs = createInsertionSeq(mainChain, pendChain, jacobSequence);
    (void) pairs;
    
    //printVec(jacobSequence);
    
    return sortedVector;
}

void    PmergeMe::fordJohnsonVector(std::vector<int> &vector) {
    
    std::vector<int> mainChain;
    std::vector<int> pendChain;

    pairComparison(mainChain, pendChain, vector);
    mergeSortVec(mainChain, pendChain, 0, mainChain.size() -1);

    if (pendChain.size() > 0)
        vector = insertVec(mainChain, pendChain);


}

void    PmergeMe::printVec(std::vector<int> &vector) {
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
