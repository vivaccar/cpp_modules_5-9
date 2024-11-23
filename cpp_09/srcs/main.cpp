#include "../includes/BitcoinExchange.hpp"

double getValue(std::string &line)
{
    unsigned int i = line.find(',');
    double value = std::strtod(line.substr(i + 1, line.length()).c_str(), NULL);
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
        std::string key = getDate(line);
        double value = getValue(line);
        std::cout << key << " " << value << std::endl;
        btcExchange.addElement(key, value);
    }
}

void    parse(int ac, char **av, BitcoinExchange &btcExchange)
{
    (void) btcExchange;
    (void) av;
    if (ac != 2)
        throw (std::invalid_argument("Invalid number of arguments\nTry: ./btc \"input_file\""));
    std::ifstream inputFile;
    std::ifstream btcDataBase;
    inputFile.open(av[1]);
    btcDataBase.open("data.csv");
/*     if (!inputFile.is_open() || !btcDataBase.is_open())
        throw (std::invalid_argument("Can't open file")); */
    fillMap(btcExchange, btcDataBase);
}

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;

    try
    {
        parse(ac, av, btcExchange);
        // find value
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}