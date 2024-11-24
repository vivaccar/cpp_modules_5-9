#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cstdlib>


class BitcoinExchange {
    private:
        std::map<std::string, float> _btcValues;
        
    public:
        
        BitcoinExchange();
        BitcoinExchange(std::map<std::string, float> map);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &other);

        void    addElement(const std::string &key, const float &value);
        void    print();

        class NotPositiveNumber : public std::exception {
            public:
                const char *what() const throw();
        };

        class TooLargeNumber : public std::exception {
            public:
                const char *what() const throw();
        };

        class BadInputDate : public std::exception {
            public:
                const char *what() const throw();
        };

};

#endif