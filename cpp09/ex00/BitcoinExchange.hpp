/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul            #+#    #+#              */
/*   Updated: 2025/08/26 07:36:53 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <cstdlib>
#include <sstream>

class BitcoinExchange
{
  private:
    std::map<std::string, double> exchangeRates;

    void parseDatabaseContent(std::ifstream &dbFile);
    void processInputLine(const std::string &line) const;
    void parseAndValidateLine(const std::string &line, std::string &date, double &value) const;
    double findClosestRate(const std::string &date) const;
    void validateInputDate(const std::string &date) const;
    void validateDateFormat(const std::string &date, int &year, int &month, int &day) const;
    void validateInputValue(double value) const;

  public:
    BitcoinExchange(const std::string &dbFile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    BitcoinExchange &operator=(const BitcoinExchange &src);

    void processInputFile(const std::string &inputFile) const;

    class CouldNotOpenFileException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class InvalidDateException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class NotAPositiveNumberException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class NumberTooLargeException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class NoRateFoundException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};
