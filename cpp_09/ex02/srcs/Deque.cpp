#include "../includes/PmergeMe.hpp"

void    pairComparisonDeq(std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &deque)
{
    for (unsigned int i = 0; i < deque.size() - 1; i += 2)
    {
        if (deque[i] > deque[i + 1])
        {
            mainChain.push_back(deque[i]);
            pendChain.push_back(deque[i + 1]);
        }
        else
        {
            mainChain.push_back(deque[i + 1]);
            pendChain.push_back(deque[i]);
        }
    }
    if (deque.size() % 2 == 1)
        pendChain.push_back(deque[deque.size() - 1]);
}

void mergeDeq(std::deque<int> &mainChain, std::deque<int> &pendChain, int left, int mid, int right) {
    std::deque<int> leftMain(mainChain.begin() + left, mainChain.begin() + mid + 1);
    std::deque<int> rightMain(mainChain.begin() + mid + 1, mainChain.begin() + right + 1);
    std::deque<int> leftPend(pendChain.begin() + left, pendChain.begin() + mid + 1);
    std::deque<int> rightPend(pendChain.begin() + mid + 1, pendChain.begin() + right + 1);
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
    while (leftIdx < leftMain.size())
    {
        mainChain[mainIdx] = leftMain[leftIdx];
        pendChain[mainIdx] = leftPend[leftIdx];
        leftIdx++;
        mainIdx++;
    }
    while (rightIdx < rightMain.size())
    {
        mainChain[mainIdx] = rightMain[rightIdx];
        pendChain[mainIdx] = rightPend[rightIdx];
        rightIdx++;
        mainIdx++;
    }
}

void    mergeSortDeq(std::deque<int> &mainChain, std::deque<int> &pendChain, int left, int right)
{
    if (left >= right)
        return ;
    int mid = left + (right - left) / 2;
    mergeSortDeq(mainChain, pendChain, left, mid);
    mergeSortDeq(mainChain, pendChain, mid + 1, right);
    mergeDeq(mainChain, pendChain, left, mid, right);
}

std::deque<int>    Jacobsthal(size_t size)
{
    std::deque<int> jacobSequence;

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


void binaryInsertDeq(std::deque<int> &deq, int value, int size)
{
    if (static_cast<int>(deq.size()) < size)
        size = static_cast<int>(deq.size());

    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (deq[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    deq.insert(deq.begin() + left, value);
}

void    printDeq(std::deque<int> &deque) {
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Função principal para criar e gerenciar a sequência de inserção
void insertion(std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> jacobSequence)
{
    std::deque<int>::iterator pendIt = pendChain.begin();
    int groupIdx = 1;
    for (std::deque<int>::iterator jacobIt = jacobSequence.begin(); jacobIt != jacobSequence.end(); jacobIt++)
    {
        std::cout << "\n\n";
        std::cout << "NEXT GROUP WILL BE INSERTED:\nJacob number(GROUP SIZE) --> " << *jacobIt << std::endl;
        std::cout << "MAIN CHAIN--> ";
        printDeq(mainChain);
        std::cout << "\nPEND CHAIN-->";
        printDeq(mainChain);
        
        
        int nbrsLeft = std::distance(pendIt, pendChain.end());
        int size = *jacobIt;
        if (nbrsLeft < size)
            size = nbrsLeft;
        std::deque<int> group(pendIt, pendIt + size);
        int mainLenght = std::pow(2, groupIdx + 1) - 1;
        for (std::deque<int>::iterator insertionIt = group.end() - 1; insertionIt != group.begin(); insertionIt--)
            binaryInsertDeq(mainChain, *insertionIt, mainLenght);
        binaryInsertDeq(mainChain, *group.begin(), mainLenght);
        std::cout << "\nGROUP TO INSERT --> ";
        printDeq(group);
        std::cout << "\nGROUP size--> " << size << std::endl;
        std::cout << "Main size to find " << mainLenght << std::endl;
        printDeq(mainChain);
        pendIt += size;
        groupIdx++;
    }
}



void    insertDeq(std::deque<int> &mainChain, std::deque<int> &pendChain) {
    
    // insiro o primeiro elemento de pend no inicio de mainChain
    mainChain.insert(mainChain.begin(), pendChain[0]);
    pendChain.erase(pendChain.begin());
    
    if (pendChain.size() == 0)
        return ;
    std::deque<int> jacobSequence = Jacobsthal(pendChain.size());
    insertion(mainChain, pendChain, jacobSequence);
}