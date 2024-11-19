#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <string>
#include <list>
#include <vector>
#include <limits.h>

#define BLUE "\033[34m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class Span {
    private:
        const unsigned int size;
        std::list<int> numbers;

    public:
        Span();
        Span(unsigned int size);
        Span(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        Span(const Span &other);
        ~Span();
        
        unsigned int getSize();

        void addNumber(int n);
        void print();
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif