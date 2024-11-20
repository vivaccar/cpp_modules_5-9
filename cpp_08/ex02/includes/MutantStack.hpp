#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string.h>
#include <stack>
#include <deque>
#include "MutantStack.tpp"

#define BLUE "\033[34m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"


template <typename T>
class MutantStack : public std::stack<T> {
    
    public:
        
        MutantStack();
        MutantStack(const MutantStack &other);
        ~MutantStack();
        MutantStack &operator=(const MutantStack &other);
        
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        
        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;
};

#endif