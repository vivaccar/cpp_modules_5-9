#include "../includes/Span.hpp"

Span::Span() : size(0) {}

Span::Span(unsigned int size) : size(size) {}

Span::Span(const Span &other) : size(other.size), numbers(other.numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span &other) {
    if (this == &other)
        return *this;
    this->size = other.size;
    this->numbers = other.numbers;
    return *this;
}

unsigned int Span::getSize() {
    return this->size;
}

void Span::addNumber(int n) {
    if (numbers.size() == this->size)
        throw (std::out_of_range("Impossible to add more values"));
    numbers.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (this->numbers.size() + std::distance(begin, end) > this->size)
        throw (std::out_of_range("Impossible to add more values to container"));
    this->numbers.insert(numbers.end(), begin, end);
}

void Span::print() {
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << std::endl;
    }
}

unsigned int Span::shortestSpan() {
    if (this->numbers.size() < 2)
        throw (std::out_of_range("No span: Less than 2 values"));
    this->numbers.sort();
    
    unsigned int current = UINT_MAX;
    
    for (std::list<int>::iterator it = numbers.begin(), itNext = ++(numbers.begin()); itNext != this->numbers.end(); it++, itNext++)
    {
        unsigned int distance = *itNext - *it;
        if (distance < current)
            current = distance;
    }
    return current;
}

unsigned int Span::longestSpan() {
    if (this->numbers.size() < 2)
        throw (std::out_of_range("No span: Less than 2 values"));
    this->numbers.sort();
    std::list<int>::iterator lower = numbers.begin();
    std::list<int>::iterator higher = numbers.end();
    higher--;
    return (*higher - *lower);
}
