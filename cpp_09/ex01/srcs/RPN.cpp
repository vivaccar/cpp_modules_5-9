#include "../includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) :_stack(other._stack) {};

RPN::~RPN() {}

RPN& RPN::operator=(const RPN &other) {
    (void) other;
    if (this == &other)
        return *this;
    this->_stack = other._stack;
    return *this;
}

double RPN::getTop() {
    return _stack.top();
}

bool    isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

void    RPN::calculate(char op) {
    double second = _stack.top();
    _stack.pop();
    double first = _stack.top();
    _stack.pop();

    if (op == '+')
        _stack.push(first + second);
    else if (op == '-')
        _stack.push(first - second);
    else if (op == '*')
        _stack.push(first * second);
    else
    {
        if (second == 0)
            throw (std::invalid_argument("Error: Division by Zero"));
        _stack.push(first / second);
    }
}

void    RPN::check(std::string notation, unsigned int i) {
    if (!std::isdigit(notation[i]) && !isOperator(notation[i]))
        throw (std::invalid_argument("Error"));
    if (isOperator(notation[i]) && _stack.size() < 2)
        throw (std::invalid_argument("Error"));
}

RPN::RPN(std::string notation) {
    for (unsigned int i = 0; i < notation.length(); i++)
    {
        if (std::isspace(notation[i]))
            continue;
        if (std::isdigit(notation[i]))
        {
            _stack.push(notation[i] - 48);
            if (notation[i + 1] && notation[i + 1] != ' ')
                throw (std::invalid_argument("Error"));
        }    
        RPN::check(notation, i);
        if (_stack.size() >= 2 && isOperator(notation[i]))
        {
            RPN::calculate(notation[i]);
        }
    }
    if (_stack.size() != 1)
        throw (std::invalid_argument("Error"));
}



