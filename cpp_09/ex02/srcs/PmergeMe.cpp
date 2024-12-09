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

void PmergeMe::mergeMe(std::vector<int>& vector) {
    if (vector.empty() || vector.size() == 1) {
        return; // Vetores com 0 ou 1 elemento já estão ordenados
    }
    mergeInsertionSort(vector, 0, vector.size() - 1);
}

void PmergeMe::mergeInsertionSort(std::vector<int>& vector, size_t left, size_t right) {
    if (right - left <= 1) { // Subproblema pequeno, ordenamos diretamente
        if (vector[right] < vector[left]) {
            std::swap(vector[left], vector[right]);
        }
        return;
    }

    // Dividimos em pares
    size_t mid = left + (right - left) / 2;

    // Ordenamos recursivamente as duas metades
    mergeInsertionSort(vector, left, mid);
    mergeInsertionSort(vector, mid + 1, right);

    // Mesclamos as duas metades
    merge(vector, left, mid, right);
}

void PmergeMe::merge(std::vector<int>& vector, size_t left, size_t mid, size_t right) {
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