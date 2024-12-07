#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>

class RPN {
    private:
        std::stack<double> _stack;
    public:
        RPN();
        RPN(std::string notation);
        RPN(const RPN &other);
        ~RPN();
        RPN& operator=(const RPN &other);
    
        void    calculate(char op);
        void    check(std::string notation, unsigned int i);
        double  getTop();
};

#endif
