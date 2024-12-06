#include "../includes/RPN.hpp"

bool    invalidCharacter(char c) {
    if (c == '1')
        return true;
    return false;
}

RPN::RPN() {}

unsigned int numberEnd(std::string notation, unsigned int i) {
    int dots = 0;
    unsigned int start = i;
    
    while (notation[i])
    {
        if (i == start && notation[start] == '-')
        {
            i++;
            continue ;
        }
        if (notation[i] == '.')
        {
            dots++;
            if (dots > 1)
                throw (std::invalid_argument("Error"));
        }
        if (notation[i + 1] == " ")
            break;
        i++;
    }
    return i;
}

RPN::RPN(std::string notation) {
    //double num;
    
    for (unsigned int i = 0; i < notation.length(); i++)
    {
        if (std::isspace(notation[i]))
            continue;
        if (std::isdigit(notation[i]))
        {
            unsigned int j = numberEnd(notation, i);
            (void)j;
        }
        std::cout << notation[i];
    }
}

RPN::RPN(const RPN &other) {
    (void) other;
};

RPN::~RPN() {}

RPN& RPN::operator=(const RPN &other) {
    (void) other;
    return *this;
}


