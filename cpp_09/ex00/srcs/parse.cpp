#include "../includes/BitcoinExchange.hpp"

void    BitcoinExchange::fillMap(BitcoinExchange &btcExchange, std::ifstream &btcDataBase)
{
    std::string line;    
    (void) btcExchange;
    std::getline(btcDataBase, line);
    if (line != "date,exchange_rate")
        throw (std::invalid_argument("Missing \"date,exchange_rate\" on first line"));
    while (std::getline(btcDataBase, line))
    {
        if (line.empty())
            continue;
        std::string key = getDate(line);
        long double value = getValue(line);
        btcExchange.addElement(key, value);
    }
}


void    BitcoinExchange::runInputFile(char *fileName, BitcoinExchange &btcExchange)
{
    
    (void) btcExchange;
    std::ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile.is_open())
        throw (std::invalid_argument("Error: could not open file."));
    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
        throw (std::invalid_argument("Missing \"date | value\" on first line"));
    while (std::getline(inputFile, line))
    {
        try
        {
            if (emptyLine(line))
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

void    BitcoinExchange::parseDataBase(int ac, BitcoinExchange &btcExchange)
{
    if (ac != 2)
        throw (std::invalid_argument("Error: could not open file."));
    std::ifstream btcDataBase;
    btcDataBase.open("data.csv");
    if (!btcDataBase.is_open())
        throw (std::invalid_argument("Error: could not open file data.csv"));
    BitcoinExchange::fillMap(btcExchange, btcDataBase);
    btcDataBase.close();
}
