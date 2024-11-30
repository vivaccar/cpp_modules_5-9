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

void    fillMap(BitcoinExchange &btcExchange, std::ifstream &btcDataBase)
{
    std::string line;    
    (void) btcExchange;
    while (std::getline(btcDataBase, line))
    {
        if (line == "date,exchange_rate")
            continue;
        std::string key = getDate(line);
        long double value = getValue(line);
        //std::cout << key << " " << value << std::endl;
        btcExchange.addElement(key, value);
    }
}

void    parseDataBase(int ac, BitcoinExchange &btcExchange)
{
    if (ac != 2)
        throw (std::invalid_argument("Invalid number of arguments\nTry: ./btc \"input_file\""));
    std::ifstream btcDataBase;
    btcDataBase.open("data.csv");
    if (!btcDataBase.is_open())
        throw (std::invalid_argument("Can't open file"));
    fillMap(btcExchange, btcDataBase);
    btcDataBase.close();
}

void checkDate(std::string &date)
{
    // yyyy-mm-dd
    std::string dates[3];
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

    //validateDate(dayInt, monthInt, year)
}

float    checkValue(std::string &value)
{
    unsigned int start = 0, end = value.length() - 1;

    while (std::isspace(value[start]))
        start++;
    while (std::isspace(value[end]))
        end--;

    value = value.substr(start, end - start + 1);
    int dots = 0;
    if (value[0] == '.' || value[value.length() - 1] == '.')
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
    int month = std::atoi(date.substr(6, 2).c_str());
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

void    runInputFile(char *fileName, BitcoinExchange &btcExchange)
{
    
    (void) btcExchange;
    std::ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.is_open())
        throw (std::invalid_argument("Can't open file"));
    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
        throw (BitcoinExchange::BadInputDate());
    while (std::getline(inputFile, line))
    {
        try
        {
            if (line.length() == 0)
                continue ;
            size_t pos = line.find(" | ");
            if (pos == std::string::npos)
                throw (BitcoinExchange::BadInputDate());
            std::string date = line.substr(0, pos);
            checkDate(date);
            std::string value = line.substr(pos + 3);
            float qt = checkValue(value);
            float n = 0;
            while (true)
            {
                try
                {
                    n = btcExchange.getElement(date) * qt;
                    break ;
                }
                catch(const std::out_of_range& e)
                {
                    date = decreaseDate(date);
                }
            }
            std::cout << date << " => " << value << " = " << n << std::endl; 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    inputFile.close();
}

// 2011-01-03 => 3 = 0.9

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;

    try
    {
        parseDataBase(ac, btcExchange);
        runInputFile(av[1], btcExchange);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}