#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &other) {
    (void) other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter &other) {
    (void) other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static void toChar(const std::string &param) {
    std::cout << "Char: " << param << std::endl;
    std::cout << "Integer: " << static_cast<int>(param[0]) << std::endl;
    std::cout << "Float: " << static_cast<float>(param[0]) << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(param[0]) << std::endl;
}

static void toFloat(const std::string &param) {
    float   n = std::atof(param.c_str());
}

void ScalarConverter::convert(const std::string &param) {
    if (param.length() == 1 && !std::isdigit(param[0]) && std::isprint(param[0]))
        toChar(param);
    else if (param[param.length() - 1] == 'f')
    {
        
    }
    else
        std::cout << "ERROR" << std::endl;
}

/* 
CHAR - SE O LENGTH == 1 E NOT DIGIT 

FLOAT - SE O ULTIMO CARACTER FOR f

DOUBLE - SE TIVER UM PONTO


 */
