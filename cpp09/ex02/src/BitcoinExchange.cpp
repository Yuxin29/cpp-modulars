#include "PmergeMe.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(){
}
    
BitcoinExchange::~ BitcoinExchange(){
}

// •A valid date will always be in the following format: Year-Month-Day.
void BitcoinExchange::isValidDate(const std::string &date){
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: bad input => " + date);

    int month,day;
    // stoi will throw exception for non_digits
    try {
        month = std::stoi(date.substr(5, 2));
        day = std::stoi(date.substr(8, 2));
    }
    catch (...){
        throw std::runtime_error("Error: bad input: non digits in date => " + date);
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) 
        throw std::runtime_error("Error: bad input: non-existing date => " + date);
}

// •A valid value must be either a float or a positive integer, between 0 and 1000.
void BitcoinExchange::isValidValue(const std::string &value){
    double d;
    try{
        d = std::stod(value);
    }
    catch (...){   
        throw std::runtime_error("Error: not a number => " + value);
    }
    if (d < 0) 
        throw std::runtime_error("Error: not a positive number.");
    if (d > 1000)
        throw std::runtime_error("Error: too large a number.");
}

// Each line in this file must use the following format: "date | value".
void BitcoinExchange::isValidLine(const std::string &line, char separator, bool is_db){
    size_t sep = line.find(separator);
    if (sep == std::string::npos)
        throw std::runtime_error("Error: bad input: separator missing => " + line);
    std::string date = line.substr(0, sep);
    std::string value = line.substr(sep + 1);

    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);

    isValidDate(date);
    if (!is_db)
        isValidValue(value);
}

// iterator lower_bound(const Key& key);
// const_iterator lower_bound(const Key&  >=) const;
// return the first element which  >= key
std::string BitcoinExchange::findClosestDate(const std::string &inputDate){
    if (_data.find(inputDate) != _data.end())
        return inputDate;
    auto it = _data.lower_bound(inputDate);
    if (it == _data.begin())
        throw std::runtime_error("Error: no earlier date available for " + inputDate);
    --it;
    return it->first;
}

//publics:
// The program should:
// Read the database into a container (like std::map or std::unordered_map).
// Read the input file line by line.
// Validate the date and value.
// For each date, find the corresponding Bitcoin price. If the date doesn’t exist, use the closest lower date.
// Multiply the value by the price and output it.
// Handle errors: invalid date, negative numbers, numbers > 1000, file errors.

void BitcoinExchange::loadDatabase(const std::string &db){
    std::ifstream file(db);
    if (!file.is_open())
        throw std::runtime_error("could not open database file.");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)){
        try {
            isValidLine(line, ',', true);
            size_t sep = line.find(',');
            std::string dateStr = line.substr(0, sep);
            std::string valueStr = line.substr(sep + 1);
            double value = std::stod(valueStr);
            _data[dateStr] = value;
        }
        catch (const std::exception &){
            continue;
        }
    }

    return ; 
}

// double here is definitely enough to hold any float and int
void BitcoinExchange::loadInput(const std::string &input){
    std::ifstream file(input);
    if (!file.is_open())
        throw std::runtime_error("could not open input file.");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)){
        try {
            isValidLine(line, '|', false);
            size_t sep = line.find('|');
            std::string dateStr = line.substr(0, sep);
             std::string valueStr = line.substr(sep + 1);

            std::string dbDate = findClosestDate(dateStr);
            double price = _data[dbDate];
            double value = std::stod(valueStr);
            double result = value * price;
            // Calculate and output
            std::cout << dbDate << " => " << value << " = " 
                      << std::fixed << std::setprecision(2) << result << std::endl;
        }
        catch (const std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }

    return ;
}