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
    this->_btcValues.insert(std::make_pair(key, value));
}

float BitcoinExchange::getElement(std::string &key)  const {
    std::map<std::string, float>::const_iterator first = _btcValues.begin();
    std::map<std::string, float>::const_iterator last = _btcValues.end();
    last--;

    if (key < first->first)
        return 0;
    else if (key > last->first)
    {
        key = last->first;
        return last->second;
    }

    return (_btcValues.at(key));
}

const char *BitcoinExchange::BadInputDate::what() const throw() {
    return "Error: bad input.";
}

const char *BitcoinExchange::TooLargeNumber::what() const throw() {
    return "Error: too large number.";
}

const char *BitcoinExchange::NotPositiveNumber::what() const throw() {
    return "Error: not a positive number.";
}