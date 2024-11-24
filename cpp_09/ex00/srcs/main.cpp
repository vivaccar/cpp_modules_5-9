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
    std::string dates[3];


    //dates[0] = date.substr(0, 4);
    dates[1] = date.substr(5, 6);
    //dates[2] = date.substr(8, 8);
    std::cout << "YEAR: " << dates[0] << " MONTH: " << dates[1] << " DAY: " << dates[2] << std::endl;
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
            //std::cout << line << std::endl;
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