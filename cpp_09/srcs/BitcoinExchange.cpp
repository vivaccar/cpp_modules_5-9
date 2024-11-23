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
    this->_btcValues.insert({key, value});
}

void BitcoinExchange::print() {
    // 
}

/* float BitcoinExchange::getElement(std::string data) {

} */