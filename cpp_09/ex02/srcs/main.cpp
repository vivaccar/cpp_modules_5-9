#include "../includes/PmergeMe.hpp"

bool    isValid(std::string &nStr)
{
    for (unsigned int i = 0; i < nStr.length(); i++)
    {
        if (!std::isdigit(nStr[i]))
            return false;
    }
    return true;
}

void    fillContainers(std::vector<int> &vec, std::deque<int> &deq, char **av)
{
    long    n;
    
    av++;
    while (*av)
    {
        std::string nStr(*av);
        if (!isValid(nStr))
            throw (std::invalid_argument("Error"));
        n = std::atol(nStr.c_str());
        if (n > std::numeric_limits<int>::max() || n <= 0)
            throw (std::invalid_argument("Error"));
        vec.push_back(n);
        deq.push_back(n);
        av++;
    }
}

void    testIsSorted(std::vector<int> &vector) {
    for (std::vector<int>::iterator it = vector.begin(); it + 1 != vector.end(); it++) {
        if (*it > *(it + 1))
        {
            std::cout << RED << "ERROR: THE CONTAINER IS NOT SORTED" << RESET << std::endl;
            return;
        }
    }
    std::cout << GREEN << "CORRECT: THE CONTAINER IS SORTED" << RESET << std::endl;
}

void    testIsSorted2(std::deque<int> &deque) {
    for (std::deque<int>::iterator it = deque.begin(); it + 1 != deque.end(); it++) {
        if (*it > *(it + 1))
        {
            std::cout << RED << "ERROR: THE CONTAINER IS NOT SORTED" << RESET << std::endl;
            return;
        }
    }
    std::cout << GREEN << "CORRECT: THE CONTAINER IS SORTED" << RESET << std::endl;
}



int main(int ac, char **av)
{
    (void)ac;

    clock_t vectorTime;
    clock_t dequeTime;
    std::vector<int> vec;
    std::deque<int> deq;
    try
    {
        fillContainers(vec, deq, av);
        std::vector<int> copia(vec);
        std::cout << "Before: ";
        printVec(vec);
        vectorTime = clock();
        PmergeMe::fordJohnsonVector(vec);
        vectorTime = (double(clock() - vectorTime) / CLOCKS_PER_SEC) * 1000000.0;
        dequeTime = clock();
        PmergeMe::fordJohnsonDeque(deq);
        dequeTime = (double(clock() - dequeTime) / CLOCKS_PER_SEC) * 1000000.0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::cout << std::endl << "AFTER: ";
    printVec(vec);
    std::cout << std::endl << "Time to process a range of " << vec.size() <<
    " elements with std::vector " << vectorTime << std::endl;
    std::cout << std::endl << "Time to process a range of " << deq.size() <<
    " elements with std::deque " << dequeTime << std::endl; 
}

//testIsSorted(vec);
//testIsSorted2(deq);