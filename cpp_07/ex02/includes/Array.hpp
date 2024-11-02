#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T>
class Array {
    private:
        T* _array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);

        unsigned int size() const;
        T& operator[](unsigned int i);
 };

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    for (unsigned int i = 0; i < n; i++)
        _array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other.size()]), _size(other.size()) {
       for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (this == &other)
        return *this;
    delete [] this->_array;
    this->_array = new T[other.size()];
    this->_size = other.size();
    for (unsigned int i = 0; i < this->_size; i++)
        this->_array[i] = other._array[i];
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw std::exception();
    return _array[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    if (!this->_array)
        return 0;
    return this->_size;
}


#endif