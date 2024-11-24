#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    //std::cout << "Bitcoin Exchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> map) : _btcValues(map) {
    //std::cout << "Bitcoin Exchange with map default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _btcValues(other._btcValues) {
    //std::cout << "Bitcoin Exchange copy constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
    //std::cout << "Bitcoin Exchange destructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other)
        return *this;
    this->_btcValues = other._btcValues;
    return *this;
}

void BitcoinExchange::addElement(const std::string &key, const float &value) {
    (void) key;
    (void) value;
    this->_btcValues.insert(std::make_pair(key, value));
}

void BitcoinExchange::print() {
    // 
}

/* float BitcoinExchange::getElement(std::string data) {

} */

const char *BitcoinExchange::BadInputDate::what() const throw() {
    return "Error: bad input.";
}

const char *BitcoinExchange::TooLargeNumber::what() const throw() {
    return "Error: too large number.";
}

const char *BitcoinExchange::NotPositiveNumber::what() const throw() {
    return "Error: not a positive number.";
}