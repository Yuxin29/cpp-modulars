#pragma once

#include <string>
#include <map>

// We need to create a C++ program called btc that reads two CSV files:
// Bitcoin database (data.csv) with historical Bitcoin prices.
// Input file containing dates and amounts of Bitcoin to calculate their value.
class BitcoinExchange
{
private:
    std::map<std::string, double> _data;

    void        isValidDate(const std::string &date);
    void        isValidValue(const std::string &value);
    void        isValidLine(const std::string &line, char separator, bool is_db);
    std::string findClosestDate(const std::string &inputDate);

public:
    BitcoinExchange();
    ~ BitcoinExchange();

    void        loadDatabase(const std::string &db);
    void        loadInput(const std::string &input);
};

