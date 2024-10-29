#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

typedef enum {
    CHAR = 1,
    INT,
    FLOAT,
    DOUBLE,
};

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