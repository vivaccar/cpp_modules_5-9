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
    date = date.substr(start, start - end + 1);
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
    if (monthInt > 12)
        throw (BitcoinExchange::BadInputDate());

    std::string day = date.substr(8, 2);
    if (!std::isdigit(day[0]) || !std::isdigit(day[1]))
        throw (BitcoinExchange::BadInputDate());
    int dayInt = std::atoi(day.c_str());
    if (dayInt > 31)
        throw (BitcoinExchange::BadInputDate());

    std::cout << date << std::endl;

/*     int y = std::atoi(year.c_str());
    if (y < 0)
        throw (BitcoinExchange::BadInputDate()); */

    //std::cout << date << std::endl;
    //dates[0] = date.substr(0, 4);
    //dates[1] = date.substr(5, 6);
    //dates[2] = date.substr(8, 8);
    //std::cout << "YEAR: " << dates[0] << " MONTH: " << dates[1] << " DAY: " << dates[2] << std::endl;
}

void    checkValue(std::string &value)
{
    unsigned int start = 0, end = value.length() - 1;

    while (std::isspace(value[start]))
        start++;
    while (std::isspace(value[end]))
        end--;

    
    value = value.substr(start, end - start + 1);
    std:: cout << value << std::endl;
    for (unsigned int i = 0; i < value.length(); i++)
    {
        if (i == 0 && value[0] == '-')
            i = 1;
        //std::cout << value[i] << std::endl;
        if (!std::isdigit(value[i]))
            throw (BitcoinExchange::BadInputDate());
    }

    long long valueInt = std::atoll(value.c_str());
    if (valueInt > std::numeric_limits<int>::max())
        throw (BitcoinExchange::TooLargeNumber());
    if (valueInt < 0)
        throw (BitcoinExchange::NotPositiveNumber());
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
            checkValue(value);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    inputFile.close();
}

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