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

double    execDeque(std::deque<int> &deque)
{
    std::clock_t    start, end;
    
    start = std::clock();
    PmergeMe::mergeMeDeq(deque);
    end = std::clock();
    return ((end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000000));
}

double    execVector(std::vector<int> &vector)
{
    std::clock_t    start, end;
    
    start = std::clock();
    PmergeMe::mergeMeVec(vector);
    end = std::clock();
    return ((end - start) / static_cast<double>(CLOCKS_PER_SEC / 1000000));
}

int main(int ac, char **av)
{
    (void)ac;
    std::vector<int> vec;
    std::deque<int> deq;
    try
    {
        fillContainers(vec, deq, av);
        std::cout << "DEQUE BEFORE: ";
        PmergeMe::printDeque(deq);
        std::cout << "\nVECTOR BEFORE: ";
        PmergeMe::printVector(vec); 
        double timeDeq = execDeque(deq);
        double timeVec = execVector(vec);
        std::cout << "\nDEQUE AFTER: ";
        PmergeMe::printDeque(deq);
        std::cout << "\nVECTOR AFTER: ";
        PmergeMe::printVector(vec); 
        std::cout << "\nTime to process a range of " << deq.size() << " elements using std::deque: " << timeDeq << " us" << std::endl;
        std::cout << "Time to process a range of " << vec.size() << " elements using std::vector: " << timeVec << " us" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}