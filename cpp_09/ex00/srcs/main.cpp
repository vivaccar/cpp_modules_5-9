#include "../includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btcExchange;

    try
    {
        BitcoinExchange::parseDataBase(ac, btcExchange);
        BitcoinExchange::runInputFile(av[1], btcExchange);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}