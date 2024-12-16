#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) {
    MutantStack::operator=(other);
}

template <typename T>
MutantStack<T>::~MutantStack() {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other) {
    if (this == &other)
        return *this;
    std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
unsigned int MutantStack<T>::getSize() const {
    return this->std::stack<T>.size();
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() {
    return (this->c.begin());
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end() {
    return (this->c.end());
}

template <typename T>
typename std::deque<T>::const_iterator MutantStack<T>::begin() const {
    return (this->c.begin());
}

template <typename T>
typename std::deque<T>::const_iterator MutantStack<T>::end() const {
    return (this->c.end());
}

#endif