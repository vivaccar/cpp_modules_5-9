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
    if (((param.length() == 1) && (std::isprint(param[0])) && (param[0] < '0' || param[0] > '9')) 
        || (param.length() == 3 && param[0] == '\'' && param[2] == '\'' && std::isprint(param[1]))) 
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

    if ((param.length() == 1) || (param.length() == 3 && param[0] == '\'' 
        && std::isprint(param[1]) && param[2] == '\''))
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
            if (i == 0)
                throw std::invalid_argument("Invalid argument");
            dots++;
            if (dots > 1 || !std::isdigit(param[i + 1]))
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
    if (param[param.length() -1] == 'f' && dots == 0)
        throw std::invalid_argument("Invalid argument");
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

static void outOfRange() {
    std::cout << "Char: Out of range" << std::endl;
    std::cout << "Int: Out of range" << std::endl;
    std::cout << "Float: Out of range" << std::endl;
    std::cout << "Double: Out of range" << std::endl;
}

static void toChar(const std::string &param) {
    char    c;

    if (param.length() == 1)
        c = param[0];
    else
        c = param[1];
    std::cout << "Char: \'" << c << "\'" << std::endl;
    std::cout << "Int: " << static_cast<int>(c) << std::endl;
    std::cout << "Float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "Double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void toInt(const std::string &param) {
    
    long lI = 0;
    int  i;
    
    lI = std::atol(param.c_str());
    if (lI > std::numeric_limits<int>::max() || lI < std::numeric_limits<int>::min())
    {
        outOfRange();
        return;
    }
    i = static_cast<int>(lI);
    std::cout << "Char: ";
    if (i > std::numeric_limits<char>::max() || i < 0)
        std::cout << "Out of range" << std::endl;
    else if (!std::isprint(static_cast<char>(i)))
        std::cout << "Not displayable" << std::endl;
    else
        std::cout << "\'" << static_cast<char>(i) << "\'" << std::endl;
    
    std::cout << "Int: " << i << std::endl;
    
    std::cout << "Float: ";
    if (i > std::numeric_limits<long>::max() || i < -std::numeric_limits<long>::max())
        std::cout << "Out of range" << std::endl;
    else
        std::cout << static_cast<float>(i) << ".0f" << std::endl;
    
    std::cout << "Double: ";
    if (i > std::numeric_limits<long>::max() || i < -std::numeric_limits<long>::max())
        std::cout << "Out of range" << std::endl;
    else
        std::cout << static_cast<double>(i) << ".0" << std::endl;
}

static void toFloat(const std::string &param) {

    double lF = strtod(param.c_str(), NULL);
    if (lF > std::numeric_limits<float>::max() || lF < -std::numeric_limits<float>::max())
    {
        outOfRange();
        return;
    }
    float f = static_cast<float>(lF);
    std::cout << "Char: ";
    if (static_cast<int>(f) > std::numeric_limits<char>::max() || static_cast<int>(f) < 0)
        std::cout << "Out of range" << std::endl;
    else if (!std::isprint(static_cast<int>(f)))
        std::cout << "Not displayable" << std::endl;
    else
        std::cout << "\'" << static_cast<char>(f) << "\'" << std::endl; 

    std::cout << "Int: ";
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        std::cout << "Out of range" << std::endl;
    else
        std::cout << static_cast<int>(f) << std::endl;
    
    std::cout << "Float: ";
    if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
        std::cout << "Out of range" << std::endl;
    else
    {
        if (f - static_cast<int>(f) == 0)
            std::cout << f << ".0f" << std::endl;
        else
            std::cout << f << "f" << std::endl;
    }
    std::cout << "Double: ";
    if (f > std::numeric_limits<double>::max() || f < -std::numeric_limits<double>::max())
        std::cout << "Out of range" << std::endl;
    else
    {
        if (f - static_cast<int>(f) == 0)
            std::cout << static_cast<double>(f) << ".0" << std::endl;
        else
            std::cout << static_cast<double>(f) << std::endl;
    }
}

static void toDouble(const std::string &param) {
    
    long double ld = std::strtold(param.c_str(), NULL);
    if (ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max())
    {
        outOfRange();
        return;
    }
    double d = std::strtod(param.c_str(), NULL);

    std::cout << "Char: ";
    if (static_cast<int>(d) > std::numeric_limits<char>::max() || static_cast<int>(d) < 0)
        std::cout << "Out of range" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "Not displayable" << std::endl;
    else
        std::cout << "\'" << static_cast<char>(d) << "\'" << std::endl;

    std::cout << "Int: ";
    if (ld > std::numeric_limits<int>::max() || ld < std::numeric_limits<int>::min())
        std::cout << "Out of range" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
    
    std::cout << "Float: ";
    if (ld > std::numeric_limits<float>::max() || ld < -std::numeric_limits<float>::max())
        std::cout << "Out of range" << std::endl;
    else
    {
        if (d - static_cast<int>(d) == 0)
            std::cout << static_cast<float>(d) << ".0f" << std::endl;
        else
            std::cout << static_cast<float>(d) << "f" << std::endl;
    }
    
    std::cout << "Double: ";
    if (ld > std::numeric_limits<double>::max() || ld < -std::numeric_limits<double>::max())
        std::cout << "Out of range" << std::endl;
    else
    {
        if (d - static_cast<int>(d) == 0)
            std::cout << d << ".0" << std::endl;
        else
            std::cout << d << std::endl;
    }
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

static void makeConvert(int &type, const std::string &param) {
    
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
    makeConvert(type, param);
}

