#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>      //file stream
#include <iostream>


/**
 * @brief 	Validate the date value
 *
 * @param 	year the year part of the date
 * @param 	month the month part of the date
 * @param 	day the day part of the date
 * @return 	bool true if the date is valid, false otherwise
*
 * @note 	genral rules for valid date:
            - Year: any non-negative integer
            - Month: an integer between 1 and 12 (inclusive)
            - Day: an integer between 1 and 31 (inclusive)
                - Months with 30 days: April (4), June (6), September (9), November (11) - Day must be between 1 and 30
                - February (2):
                    - In leap years: Day must be between 1 and 29
                        - It is divisible by 4 and not divisible by 100, OR
                        - It is divisible by 400    
                    - In non-leap years: Day must be between 1 and 28  
 */
static bool    validateYearMontDay(int year, int month, int day){
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) 
        return false;
    if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day > 30)
            return false;
    }
    else if (month == 2){
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap){
            if (day > 29)
                return false;
        }
        else{
            if (day > 28)
                return false;
        }
    }
    return true;
}

/**
* @brief 	Validate the date format
* @param 	date the date string to validate
* @return 	void, throw runtime_error if the date is invalid
*
* @note 	A valid date will always be in the following format
            Year-Month-Day
            1995-11-05
*/
void BitcoinExchange::isValidDate(const std::string &date){
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Error: bad input => " + date);
    for (size_t i = 0; i < 10; i++){
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            throw std::runtime_error("Error: bad input => " + date);
    }
    int year, month, day;
    // stoi will throw exception for non_digits
    try {
        year = std::stoi(date.substr(0, 4));
        month = std::stoi(date.substr(5, 2));
        day = std::stoi(date.substr(8, 2));
    }
    catch (const std::exception&){
        throw std::runtime_error("Error: bad input: non digits in date => " + date);
    }
    if (!validateYearMontDay(year, month, day)) 
        throw std::runtime_error("Error: bad input: non-existing date => " + date);
}

/**
* @brief 	Validate the value format
* @param 	value the value string to validate
* @return 	void, throw runtime_error if the value is invalid
*
* @note 	A valid value must be either a float or a positive integer, between 0 and 1000.
            double stod(const std::string& str, size_t* pos = 0);
            value = "12abc", index = 2 < 5
*/
void BitcoinExchange::isValidValue(const std::string &value){
    double d;
    size_t index;
    try{
        d = std::stod(value, &index);
        if (index < value.length())
            throw std::runtime_error("Error: not a number => " + value);
    }
    catch (const std::exception&){
        throw std::runtime_error("Error: not a number => " + value);
    }
    if (d < 0) 
        throw std::runtime_error("Error: not a positive number.");
    if (d > 1000)
        throw std::runtime_error("Error: too large a number.");
}

/**
* @brief 	Validate the line format
* @param 	line the line string to validate
* @param 	separator the character that separates the date and value
* @param 	is_db a boolean indicating whether the line is from the database or input file(is_db, only when it is not database, we need to check value)    
* @return 	void, throw runtime_error if the line is invalid

* @note 	A valid line must contain a date and a value separated by a specific character 
            (comma for database, pipe for input).
            For database lines, only the date format needs to be validated. 
            For input lines, both the date and value formats need to be validated.
*/
void BitcoinExchange::isValidLine(const std::string &line, char separator, bool is_db){
    size_t sep = line.find(separator);
    if (sep == std::string::npos)
        throw std::runtime_error("Error: bad input => " + line);
    std::string date = line.substr(0, sep);
    std::string value = line.substr(sep + 1);
    // trim when necessary
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);
    isValidDate(date);
    if (!is_db)
        isValidValue(value);
}

/**
* @brief 	Find the closest date in the database that is less than or equal to the input date
* @param 	inputDate the date string to find the closest match for
* @return 	the closest date string from the database
* @throws 	std::runtime_error if no earlier date is available for the input date

* @example 	If the input date               "2010-06-01" 
            and the database contains       "2009-01-01", "2010-01-01", "2011-01-01", 
            the function will return        "2010-01-01" as it is the closest date that is less than or equal to the input date.
            iterator lower_bound(const Key& key);
            const_iterator lower_bound(const Key&  >=) const;
            return the first element which  >= key
*/
std::string BitcoinExchange::findClosestDate(const std::string &inputDate){
    if (_data.find(inputDate) != _data.end())
        return inputDate;
    auto it = _data.lower_bound(inputDate);
    if (it == _data.begin())
        throw std::runtime_error("Error: no earlier date available for " + inputDate);
    --it;
    return it->first;
}

/**
* @brief 	Load the database from a CSV file and store it in a map
* @param 	db the file path of the database CSV file
* @return 	void, throw runtime_error if the file cannot be opened or if any line is invalid
*
*/
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
}

/**
* @brief 	Load the input from a CSV file, validate it, and calculate the Bitcoin value based on the database
* @param 	input the file path of the input CSV file
* @return 	void, throw runtime_error if the file cannot be opened or if any line is invalid
*
* @steps    1. Read the input file line by line.
            2. Validate the date and value.
            3. For each date, find the corresponding Bitcoin price. If the date doesn’t exist, use the closest lower date.
            4. Multiply the value by the price and output it.
            5. Handle errors: invalid date, negative numbers, numbers > 1000, file errors. 
*/
void BitcoinExchange::loadInput(const std::string &input){
    std::ifstream file(input);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open input file for some reason.");
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
            std::cout << dateStr << " => " << value << " = " << value * price << std::endl;
        }
        catch (const std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
}