#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T>
void    swap(T &x, T &y) {
    T   cur = x;

    x = y;
    y = cur;
}

template <typename T>
T   min(T x, T y) {
    if (x < y)
        return x;
    return y;
}

template <typename T>
T   max(T x, T y) {
    if (x > y)
        return x;
    return y;
}

#endif