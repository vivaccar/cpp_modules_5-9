#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <cctype>
# include <limits>
# include <string>
# include <cstdlib>

enum e_type{
    CHAR = 1,
    INT,
    FLOAT,
    DOUBLE,
    IINFF,
    DINFF,
    IINF,
    DINF,
    NAN
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