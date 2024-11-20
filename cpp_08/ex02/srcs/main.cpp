#include "../includes/MutantStack.tpp"

int main()
{
    {
        std::cout << RED << "TEST 0 - SUBJECT" << RESET << std::endl;

        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    {
        std::cout << RED << "\nTEST 1" << RESET << std::endl;
        MutantStack<int> s;

        s.push(1);
        s.push(2);
        s.push(10);
        s.push(-1);

        for (MutantStack<int>::iterator it = s.begin(); it != s.end(); it++) {
            std::cout << *it << " ";
        }
    }
}