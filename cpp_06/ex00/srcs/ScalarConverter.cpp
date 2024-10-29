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

static char toChar(const std::string &param) {

}

/* static void toFloat(const std::string &param) {
    float   n = std::atof(param.c_str());
} */

static int getType(const std::string &param) {
    if (param.length() == 1 && )
}

void ScalarConverter::convert(const std::string &param) {
    int type = getType(param);
}

/* 
CHAR - SE O LENGTH == 1 E NOT DIGIT 

FLOAT - SE O ULTIMO CARACTER FOR f

DOUBLE - SE TIVER UM PONTO


 */
