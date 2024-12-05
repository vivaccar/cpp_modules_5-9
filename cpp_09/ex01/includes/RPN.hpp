#ifndef RPN_HPP
#define RPN_HPP

#include "stack"
#include "string"
#include "iostream"
#include "exception"

class RPN {
    private:
        std::stack<double> _stack;
        double             _result;
    public:
        RPN();
        RPN(std::string notation);
        RPN(const RPN &other);
        ~RPN();
        RPN& operator=(const RPN &other);
    
        //double  getResult();
};

#endif
