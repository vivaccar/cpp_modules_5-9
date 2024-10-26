#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter {
    public:
        static void convert(const std::string &param);

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter &other);

        ScalarConverter& operator=(ScalarConverter &other);
};

#endif