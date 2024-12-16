#include "../includes/BitcoinExchange.hpp"

long double getValue(std::string &line)
{
    unsigned int i = line.find(',');
    long double value = std::strtold(line.substr(i + 1, line.length()).c_str(), NULL);
    return value;
}

std::string getDate(std::string &line)
{
    unsigned int i = line.find(',');
    return (line.substr(0, i));
}

bool    isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}


void    validateDate(int d, int m, int y)
{
    if (d > 31 || m > 12)
        throw (BitcoinExchange::BadInputDate());
    if (d == 31 && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
        throw (BitcoinExchange::BadInputDate());
    if (m == 2 && d > 29)
        throw (BitcoinExchange::BadInputDate());
    if (d == 29 && m == 2 && !isLeapYear(y))
        throw (BitcoinExchange::BadInputDate());
}


void checkDate(std::string &date)
{
    // yyyy-mm-dd
    unsigned int start = 0, end = date.length() - 1;

    if (date.length() < 10)
        throw (BitcoinExchange::BadInputDate());
    
    while (std::isspace(date[start]))
        start++;
    while (std::isspace(date[end]))
        end--;
    date = date.substr(start, end - start + 1);
    if (date.length() != 10)
        throw (BitcoinExchange::BadInputDate());

    if (date[4] != '-' || date[7] != '-')
        throw (BitcoinExchange::BadInputDate());
    
    std::string year = date.substr(0, 4);
    for (unsigned int i = 0; i < 4; i++)
    {
        if (!std::isdigit(year[i]))
            throw (BitcoinExchange::BadInputDate());
    }

    std::string month = date.substr(5, 2);
    if (!std::isdigit(month[0]) || !std::isdigit(month[1]))
        throw (BitcoinExchange::BadInputDate());
    int monthInt = std::atoi(month.c_str());

    std::string day = date.substr(8, 2);
    if (!std::isdigit(day[0]) || !std::isdigit(day[1]))
        throw (BitcoinExchange::BadInputDate());
    int dayInt = std::atoi(day.c_str());
    int yearInt = std::atoi(year.c_str());

    validateDate(dayInt, monthInt, yearInt);
}

bool    emptyValue(std::string &value)
{
    for (unsigned int i = 0; i < value.length(); i++)
    {
        if (!std::isspace(value[i]))
            return false;
    }
    return true;
}

float    checkValue(std::string &value)
{
    unsigned int start = 0, end = value.length() - 1; 
    if (value.length() == 0)
        throw (BitcoinExchange::BadInputDate());
    if (emptyValue(value))
        throw (BitcoinExchange::BadInputDate());
    while (std::isspace(value[start]))
        start++;
    while (std::isspace(value[end]))
        end--;

    value = value.substr(start, end - start + 1);
    int dots = 0;
    if (value[0] == '.' || value[value.length() - 1] == '.' || value[0] == ' ')
        throw (BitcoinExchange::BadInputDate());
    for (unsigned int i = 0; i < value.length(); i++)
    {
        if (value[i] == '.')
            dots++;
        if (dots == 2)
            throw (BitcoinExchange::BadInputDate());
        if (i == 0 && value[0] == '-')
            throw (BitcoinExchange::NotPositiveNumber());
        if (!std::isdigit(value[i]) && value[i] != '.')
            throw (BitcoinExchange::BadInputDate());
    }
    long double valueInt = std::atof(value.c_str());
    if (valueInt > std::numeric_limits<int>::max())
        throw (BitcoinExchange::TooLargeNumber());
    if (valueInt < 0)
        throw (BitcoinExchange::NotPositiveNumber());
    return (static_cast<float>(valueInt));
}

std::string   decreaseDate(std::string &date)
{
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    std::ostringstream oss;


    if (day > 1)
        day--;
    else
    {
        if (month > 1)
        {
            month--;
            if (month == 4 || month == 6|| month == 9 || month == 11)
                day = 30;
            else if (month == 2)
                day = 28;
            else
                day = 31;
        }
        else
        {
            year--;
            day = 31;
            month = 12;
        }
    }
    oss << year << "-" << std::setw(2) << std::setfill('0') 
    << month << "-" << std::setw(2) << std::setfill('0') << day;
    return (oss.str());
}

bool    emptyLine(std::string &line)
{
    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (!std::isspace(line[i]))
            return false;
    }
    return true;
}