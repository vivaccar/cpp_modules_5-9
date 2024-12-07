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

void    fillContainers(std::vector<int> &vec, std::deque<int> &deq, std::string numStr)
{
    (void) vec;
    (void) deq;
    
    std::vector<std::string> numbers;
    std::stringstream       stream(numStr);
    std::string             nStr;
    long                    l;

    while (stream >> nStr)
    {
        if (!isValid(nStr))
            throw (std::invalid_argument("Error"));
        l = atol(nStr.c_str());
        std::cout << l << std::endl;
        
    }
    for (std::vector<std::string>::iterator it = numbers.begin(); it != numbers.end(); it++ )
    {
        std::cout << *it << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::vector<int> vec;
        std::deque<int> deq;
        try
        {
            fillContainers(vec, deq, av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
        return 0;
    }
    std::cout << "Error" << std::endl;
    return 1;
}