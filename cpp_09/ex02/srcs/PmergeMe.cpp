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

void PmergeMe::mergeMeVec(std::vector<int>& vector) {
    if (vector.size() <= 1) {
        return;
    }
    mergeInsertionSortVec(vector, 0, vector.size() - 1);
}

void PmergeMe::mergeInsertionSortVec(std::vector<int>& vector, size_t left, size_t right) {
    if (right - left <= 1)
    { // Subproblema
        if (vector[right] < vector[left])
            std::swap(vector[left], vector[right]);
        return;
    }

    // Dividimos em pares
    size_t mid = left + (right - left) / 2;

    // Ordenamos recursivamente as duas metades
    mergeInsertionSortVec(vector, left, mid);
    mergeInsertionSortVec(vector, mid + 1, right);

    // Mesclamos as duas metades
    mergeVec(vector, left, mid, right);
}

void PmergeMe::mergeVec(std::vector<int>& vector, size_t left, size_t mid, size_t right) {
    size_t i = left;
    size_t j = mid + 1;
    std::vector<int> temp;

    // Comparamos elementos das duas metades
    while (i <= mid && j <= right) {
        if (vector[i] <= vector[j]) {
            temp.push_back(vector[i]);
            i++;
        } else {
            temp.push_back(vector[j]);
            j++;
        }
    }

    // Copiamos os elementos restantes de cada metade
    while (i <= mid) {
        temp.push_back(vector[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(vector[j]);
        j++;
    }

    // Atualizamos o vetor original
    for (size_t k = 0; k < temp.size(); ++k) {
        vector[left + k] = temp[k];
    }
}

void    PmergeMe::mergeMeDeq(std::deque<int> &deque) {
    if (deque.size() <= 1)
        return ;
    mergeInsertionSortDeq(deque, 0, deque.size() - 1);
}

void    PmergeMe::mergeInsertionSortDeq(std::deque<int> &deque, size_t left, size_t right) {
    if (right - left <= 1)
    {
        if (deque[right] < deque[left])
            std::swap(deque[right], deque[left]);
        return;
    }
    size_t mid = left + (right - left) / 2;

    mergeInsertionSortDeq(deque, left, mid);
    mergeInsertionSortDeq(deque, mid + 1, right);

    mergeDeq(deque, left, mid, right);
}

void    PmergeMe::mergeDeq(std::deque<int> &deque, size_t left, size_t mid, size_t right) {
    size_t i = left;
    size_t j = mid + 1;
    std::deque<int> temp;

    // Comparamos elementos das duas metades
    while (i <= mid && j <= right) {
        if (deque[i] <= deque[j]) {
            temp.push_back(deque[i]);
            i++;
        } else {
            temp.push_back(deque[j]);
            j++;
        }
    }

    // Copiamos os elementos restantes de cada metade
    while (i <= mid) {
        temp.push_back(deque[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(deque[j]);
        j++;
    }

    // Atualizamos o vetor original
    for (size_t k = 0; k < temp.size(); ++k) {
        deque[left + k] = temp[k];
    }
}

void    PmergeMe::printVector(std::vector<int> &vector) {
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it;
        if (it + 1 != vector.end())
            std::cout << " ";
        else
            std::cout << std::endl;
    }
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