#pragma once

#include <string>
#include <iostream>
#include <map>

// We need to create a C++ program called btc that reads two CSV files:
//Bitcoin database (data.csv) with historical Bitcoin prices.
//Input file containing dates and amounts of Bitcoin to calculate their value.

// The program should:
// Read the database into a container (like std::map or std::unordered_map).
// Read the input file line by line.
// Validate the date and value.
// For each date, find the corresponding Bitcoin price. If the date doesn’t exist, use the closest lower date.
// Multiply the value by the price and output it.
// Handle errors: invalid date, negative numbers, numbers > 1000, file errors.
class BitcoinExchange
{
private:
    //double here is definitely enough to hold any float and int
    std::map<std::string, double> _data;

    // Each line in this file must use the following format: "date | value".
    // •A valid date will always be in the following format: Year-Month-Day.
    // •A valid value must be either a float or a positive integer, between 0 and 1000.
    void isValidLine(const std::string &line);
    void isValidDate(const std::string &date);
    void isValidValue(const std::string &value);
    std::string findClosestDate(const std::string &inputDate);

public:
    BitcoinExchange();
    ~ BitcoinExchange();

    void loadDatabase(const std::string &db);
    void loadInput(const std::string &input);
};

