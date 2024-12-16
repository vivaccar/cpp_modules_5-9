#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <limits.h>
#include <sstream>
#include <iomanip>

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
        float   getElement(std::string &key) const;

        static void fillMap(BitcoinExchange &btcExchange, std::ifstream &btcDataBase);
        static void parseDataBase(int ac, BitcoinExchange &btcExchange);
        static void runInputFile(char *fileName, BitcoinExchange &btcExchange);
        
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

long double getValue(std::string &line);
std::string getDate(std::string &line);
bool        isLeapYear(int year);
void        validateDate(int d, int m, int y);
void        checkDate(std::string &date);
bool        emptyValue(std::string &value);
float       checkValue(std::string &value);
std::string decreaseDate(std::string &date);
bool        emptyLine(std::string &line);

#endif