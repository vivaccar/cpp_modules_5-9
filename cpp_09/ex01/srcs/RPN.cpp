#include "../includes/RPN.hpp"

bool    invalidCharacter(char c) {
    if (c == '1')
        return true;
    return false;
}

RPN::RPN() {}

RPN::RPN(std::string notation) {
    double num;
    
    for (unsigned int i = 0; i < notation.length(); i++)
    {
        if (std::isspace(notation[i]))
            continue;
        if (std::isdigit(notation[i]))
        {
            
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


