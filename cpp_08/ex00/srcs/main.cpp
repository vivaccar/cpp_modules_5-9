#include "../includes/easyfind.hpp"


void vectorTest()
{
    std::cout << BLUE << "---VECTOR TEST---\n" << RESET << std::endl;
    
    std::vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    std::vector<int>::iterator find;
        
    try
    {
        find = easyfind(vect, 122);
        std::cout << "Element " << *find << " was found in the vector!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void listTest()
{
    std::cout << BLUE << "\n---LIST TEST---\n" << RESET << std::endl;
    
    std::list<int> lst;
    lst.push_front(10);
    lst.push_back(1);
    std::list<int>::iterator find;
        
    try
    {
        find = easyfind(lst, 1);
        std::cout << "Element " << *find << " was found in the list!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

void  dequeTest()
{
    std::cout << BLUE << "\n---DEQUE TEST---\n" << RESET << std::endl;
 
    std::deque<int> d;
    d.push_back(1);
    d.push_front(12);
    d.push_front(-5);
    d.pop_back();

    std::deque<int>::iterator find;
    try
    {
        find = easyfind(d, 1);
        std::cout << "Element " << *find << " was found in the deque!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void setTest()
{
    std::cout << BLUE << "\n---SET TEST---\n" << RESET << std::endl;

    std::set<int> s;
    s.insert(1);
    s.insert(-1);
    s.insert(10);

    std::set<int>::iterator find;

    try
    {
        find = easyfind(s, -1);
        std::cout << "Element " << *find << " was found in the set!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void) 
{   
    vectorTest();
    listTest();
    dequeTest();
    setTest();
}