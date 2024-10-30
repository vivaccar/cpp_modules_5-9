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


bool isChar(const std::string &param) {
    if (param.length() == 1 && std::isprint(param[0]))
        return true;
    return false;
}

bool isInt(const std::string &param) {
    for (size_t i = 0; i < param.length(); i++)
    {
        if (i == 0 && param[0] == '-')
            i++;
        if (param[i] == '.' || param[i] == 'f')
            return false;
    }
    return true;
}

bool isFloat(const std::string &param) {
    if (param[param.length() - 1] != 'f')
        return false;
    return (true);
}

bool isDouble(const std::string &param) {
    if (param.find('.') != std::string::npos)
        return true;
    return false;
}

static void checkInvalidArg(const std::string &param)
{
    int dots = 0;

    if (param.length() == 1)
        return;
    for (size_t i = 0; i < param.length(); i++)
    {
        if (i == 0 && param[0] == '-')
        {
            i++;
            if (param[i] == '.' || param[i] == 'f' || !param[i])
                throw std::invalid_argument("Invalid argument");
        }
        if (param[i] == '.')
        {
            dots++;
            if (dots > 1)
                throw std::invalid_argument("Invalid argument");
        }
        else if (!std::isdigit(param[i]))
        {
            if (param[i] != 'f')
                throw std::invalid_argument("Invalid argument");
            else if (param[i] == 'f' && i != param.length() - 1)
                throw std:: invalid_argument("Invalid argument");
        }
    }
}

static int parse(const std::string &param) {
    std::string pseudoLiterals[5] = {"-inff", "+inff", "-inf", "+inf", "nan"};
    int pseudoTypes[5] = {DINFF, IINFF, DINF, IINF, NAN};

    for (int i = 0; i < 5; i++)
    {
        if (param == pseudoLiterals[i])
            return pseudoTypes[i];
    }
    checkInvalidArg(param);
    if (isChar(param))
        return CHAR;
    if (isInt(param))
        return INT;
    if (isFloat(param))
        return FLOAT;
    if (isDouble(param))
        return DOUBLE;
    return 0;
}

static void toChar(const std::string &param) {
    char c = param[0];

    std::cout << "Char: " << c << std::endl;
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(c) << std::endl;
}

static void toInt(const std::string &param) {
    int i = std::atoi(param.c_str());

    // verificar se e possivel fazer o cast para char!!
    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: " << i << std::endl;
    std::cout << "Float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(i) << std::endl;
}

static void toFloat(const std::string &param) {
    float f = std::strtof(param.c_str(), NULL);

    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: " << static_cast<int>(f) << std::endl;
    std::cout << "Float: " << f << "f" << std::endl;
    std::cout << "Double: " << static_cast<double>(f) << std::endl;
}

static void toDouble(const std::string &param) {
    double d = std::strtod(param.c_str(), NULL);

    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: " << static_cast<int>(d) << std::endl;
    std::cout << "Float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "Double: " << d << std::endl;
}

static void toIinff(const std::string &param) {
    (void) param;
    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: Impossible to convert" << std::endl;
    std::cout << "Float: " << "+inff" << std::endl;
    std::cout << "Double: " << "+inf" << std::endl;
}

static void toDinff(const std::string &param) {
    (void) param;
    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: Impossible to convert" << std::endl;
    std::cout << "Float: " << "-inff" << std::endl;
    std::cout << "Double: " << "-inf" << std::endl;
}

static void toIinf(const std::string &param) {
    (void) param;
    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: Impossible to convert" << std::endl;
    std::cout << "Float: " << "+inff" << std::endl;
    std::cout << "Double: " << "+inf" << std::endl;
}

static void toDinf(const std::string &param) {
    (void) param;
    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: Impossible to convert" << std::endl;
    std::cout << "Float: " << "-inff" << std::endl;
    std::cout << "Double: " << "-inf" << std::endl;
}

static void toNan(const std::string &param) {
    (void) param;
    std::cout << "Char: Impossible to convert" << std::endl;
    std::cout << "Int: Impossible to convert" << std::endl;
    std::cout << "Float: " << "nanf" << std::endl;
    std::cout << "Double: " << "nan" << std::endl;
}

static void doConversion(int &type, const std::string &param) {
    
    int     types[] = {CHAR, INT, FLOAT, DOUBLE, IINFF, DINFF, IINF, DINF, NAN};
    void    (*converters[])(const std::string &param) = { 
        &toChar, 
        &toInt, 
        &toFloat, 
        &toDouble, 
        &toIinff,
        &toDinff,
        &toIinf,
        &toDinf,
        &toNan,
        };

    for (int i = 0; i < 9; i++)
    {
        if (type == types[i])
            converters[i](param);
    }
}

void ScalarConverter::convert(const std::string &param) {
    int type = parse(param);

    std::cout << type << std::endl;
    doConversion(type, param);
}


/* 
CHAR - SE O LENGTH == 1 E NOT DIGIT 

FLOAT - SE O ULTIMO CARACTER FOR f

DOUBLE - SE TIVER UM PONTO


 */
