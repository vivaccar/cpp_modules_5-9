#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iterate(T &e) {

    std::cout << e << std::endl;
}

template <typename T>
void iter(T *array, size_t length, void (*f)(T &e)) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif