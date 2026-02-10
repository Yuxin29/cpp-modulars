#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac == 1){
        std::cout << "Error: could not open file\n";
        return 1;
    }
    if (ac != 2){
        std::cout << "Error: wrong arguement number\n";
        return 1;
    }

    try {
        BitcoinExchange my_btc;
        my_btc.loadDatabase("data.csv");
        my_btc.loadInput(av[1]);
    }
    catch (const std::runtime_error &e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}