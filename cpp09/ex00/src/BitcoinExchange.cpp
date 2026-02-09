#include "BitcoinExchange.hpp"
#include "stdexcept"

BitcoinExchange::BitcoinExchange(){
}
    
BitcoinExchange::~ BitcoinExchange(){
}

//private helpers:
// Each line in this file must use the following format: "date | value".
// •A valid date will always be in the following format: Year-Month-Day.
// •A valid value must be either a float or a positive integer, between 0 and 1000.
void BitcoinExchange::isValidLine(const std::string &line){
    size_t sep = line.find('|');
    if (sep == std::string::npos)
        throw std::runtime_error("Error: bad input => " + line);
    std::string date = line.substr(0, sep);
    std::string value = line.substr(sep + 1);

    // Trim spaces
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);

    // Call date and value validators
    isValidDate(date);
    isValidValue(value);
}

void BitcoinExchange::isValidDate(const std::string &date){
    if (date.size() != 10 || date[4] != '-' || date[6] != '-')
        throw std::runtime_error("Error: bad input => " + date);

    int year, month,day;
    try {
        year = std::stoi(date.substr(0, 4));
        month = std::stoi(date.substr(5, 2));
        day = std::stoi(date.substr(8, 2));
    }
    catch (...)
        throw std::runtime_error("Error: bad input => " + date);

    if (month < 1 || month > 12 || day < 1 || day > 31) 
        throw std::runtime_error("Error: bad input => " + date);
}

void BitcoinExchange::isValidValue(const std::string &value){
    double d;
    try
        v = std::stod(value);
    catch (...)
        throw std::runtime_error("Error: not a number => " + value);

    if (v < 0) 
        throw std::runtime_error("Error: not a positive number.");
    if (v > 1000)
        throw std::runtime_error("Error: too large a number.");
}

std::string BitcoinExchange::findClosestDate(const std::string &inputDate){

}

//publics
void BitcoinExchange::loadDatabase(const std::string &db){
    std::ifstream file(db);
    if (!file.is_open())
        throw std::runtime_error("could not open database file.");
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)){
        std::string dateStr = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 1);
        try {
            isValidLine(line);
            double value = std::stod(valueStr);
            _date[date] = dateStr;
        }
        catch {
            continue;
        }
    }

    return ; 
}

void BitcoinExchange::loadInput(const std::string &input){
    return ;
}