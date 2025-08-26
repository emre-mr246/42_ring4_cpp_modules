/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:29 by emgul            #+#    #+#              */
/*   Updated: 2025/08/26 07:36:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string &dbFilename)
{
    std::ifstream dbFile;

    dbFile.open(dbFilename.c_str());
    if (!dbFile.is_open())
        throw(CouldNotOpenFileException());
    parseDatabaseContent(dbFile);
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
        this->exchangeRates = src.exchangeRates;
    return (*this);
}

void BitcoinExchange::processInputFile(const std::string &inputFilename) const
{
    std::string line;
    std::ifstream inputFile;

    inputFile.open(inputFilename.c_str());
    if (!inputFile.is_open())
        throw(CouldNotOpenFileException());
    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
        processInputLine(line);
}

void BitcoinExchange::processInputLine(const std::string &line) const
{
    std::string date;
    double value;
    double rate;
    double result;

    try
    {
        parseAndValidateLine(line, date, value);
        rate = findClosestRate(date);
        result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    } catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void BitcoinExchange::parseAndValidateLine(const std::string &line, std::string &date, double &value) const
{
    std::istringstream iss(line);
    std::string separator;
    std::string valueStr;
    char *end;

    if (!(iss >> date >> separator >> valueStr))
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    if (separator != "|")
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }
    validateInputDate(date);
    value = std::strtod(valueStr.c_str(), &end);
    if (end == valueStr.c_str() || *end != '\0')
    {
        std::cerr << "Error: not a valid number." << std::endl;
        return;
    }
    validateInputValue(value);
}

void BitcoinExchange::parseDatabaseContent(std::ifstream &dbFile)
{
    std::istringstream iss;
    std::string line;
    std::string date;
    double rate;

    std::getline(dbFile, line);
    while (std::getline(dbFile, line))
    {
        iss.clear();
        iss.str(line);
        if (std::getline(iss, date, ',') && (iss >> rate))
            this->exchangeRates[date] = rate;
    }
}

double BitcoinExchange::findClosestRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it;

    if (exchangeRates.empty())
        throw(NoRateFoundException());
    it = exchangeRates.find(date);
    if (it != exchangeRates.end())
        return (it->second);
    it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin())
        throw(NoRateFoundException());
    it--;
    return (it->second);
}

void BitcoinExchange::validateInputDate(const std::string &date) const
{
    int year;
    int month;
    int day;
    bool isLeap;

    validateDateFormat(date, year, month, day);
    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        throw(InvalidDateException());
    if (month == 2)
    {
        isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28))
            throw(InvalidDateException());
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) &&
             day > 30)
        throw(InvalidDateException());
}

void BitcoinExchange::validateDateFormat(const std::string &date, int &year, int &month, int &day) const
{
    char dash1;
    char dash2;
    std::istringstream ss;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw(InvalidDateException());
    ss.str(date);
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (ss.fail() || dash1 != '-' || dash2 != '-')
        throw(InvalidDateException());
}

void BitcoinExchange::validateInputValue(double value) const
{
    if (value < 0)
        throw(NotAPositiveNumberException());
    if (value > 1000)
        throw(NumberTooLargeException());
}

const char *BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
    return ("could not open file.");
}
const char *BitcoinExchange::InvalidDateException::what() const throw()
{
    return ("bad input.");
}
const char *BitcoinExchange::NotAPositiveNumberException::what() const throw()
{
    return ("not a positive number.");
}
const char *BitcoinExchange::NumberTooLargeException::what() const throw()
{
    return ("too large a number.");
}
const char *BitcoinExchange::NoRateFoundException::what() const throw()
{
    return ("no rate found for the given date.");
}
