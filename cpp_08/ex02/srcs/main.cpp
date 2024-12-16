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
        std::cout << RED << "\nmyTEST <int>" << RESET << std::endl;
        MutantStack<int> s;

        s.push(1);
        s.push(2);
        s.push(10);
        s.push(-1);
        s.push(12);

        for (MutantStack<int>::iterator it = s.begin(); it != s.end(); it++) {
            *it = *it + 5; 
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        //const iterator
        for (MutantStack<int>::const_iterator it = s.begin(); it != s.end(); it++) {
            //*it = *it + 5; 
            std::cout << *it << " ";
        }
    }

    {
        std::cout << RED << "\n\nmyTEST <string>" << RESET << std::endl;
        MutantStack<std::string> s;

        s.push("Hello");
        s.push("World");
        s.push(" ");
        s.push("42");
        s.push("\\o/");

        for (MutantStack<std::string>::iterator it = s.begin(); it != s.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << RED << "\nmyTEST Copy operator and assignment" << RESET << std::endl;
        MutantStack<std::string> s;

        s.push("Hello");
        s.push("World");
        s.push(" ");
        s.push("42");
        s.push("\\o/");

        MutantStack<std::string> s2(s);
        MutantStack<std::string> s3;
        s3 = s;

        for (MutantStack<std::string>::iterator it = s2.begin(); it != s2.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        for (MutantStack<std::string>::iterator it = s3.begin(); it != s3.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}