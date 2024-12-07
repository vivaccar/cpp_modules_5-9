#include "../includes/RPN.hpp"

bool    isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

RPN::RPN() {}

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
            _stack.push(notation[i] - 48);
        RPN::check(notation, i);
        if (_stack.size() >= 2 && isOperator(notation[i]))
        {
            RPN::calculate(notation[i]);
        }
    }
    if (_stack.size() != 1)
        throw (std::invalid_argument("Error"));
}

double RPN::getTop() {
    return _stack.top();
}

RPN::RPN(const RPN &other) {
    (void) other;
};

RPN::~RPN() {}

RPN& RPN::operator=(const RPN &other) {
    (void) other;
    if (this == &other)
        return *this;
    this->_stack = other._stack;
    return *this;
}


