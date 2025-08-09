/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:29 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:46 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <cstdlib>

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called for ScalarConverter" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called for ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
    std::cout << "Copy constructor called for ScalarConverter" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    if (this == &src)
        return (*this);
    std::cout << "Copy assignment operator called for ScalarConverter" << std::endl;
    return (*this);
}

void print(std::string c, std::string i, std::string f, std::string d)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

std::string getChar(const std::string &input, int type)
{
    int a;
    
    if (type == SPECIAL)
        return ("impossible");
    a = atoi(input.c_str()); 
    if (type == DOUBLE || type == FLOAT || type == INT)
    {
        if (a < 32 || a > 126)
            return ("Non displayable");
        else
            return std::string("'") + static_cast<char>(a) + "'";
    }
    return ("\'" + input + "\'");
}

std::string getInt(const std::string &input, int type)
{
    int res;
    std::stringstream ss;
    std::string floatStr;

    if (type == INT)
        return (input);
    if (type == SPECIAL)
        return ("impossible");
    if (type == FLOAT)
    {
        floatStr = input.substr(0, input.length() - 1);
        res = static_cast<int>(std::atof(floatStr.c_str()));
        ss << res;
        return (ss.str());
    }
    if (type == DOUBLE)
    {
        res = std::atoi(input.c_str());
        ss << static_cast<int>(res);
        return (ss.str());
    }
    res = static_cast<int>(input.c_str()[0]);
    ss << res;
    return (ss.str());
}

std::string getFloat(const std::string &input, int type)
{
    float res;
    std::stringstream ss;
	std::string floatStr;

    if (type == FLOAT)
    {
        floatStr = input.substr(0, input.length() - 1);
        res = std::atof(floatStr.c_str());
        if (res == static_cast<int>(res))
            ss << res << ".0f";
        else
            ss << res << "f";
        return (ss.str());
    }
    if (type == SPECIAL)
    {
        if (input == "nanf" || input == "inf" || input == "-inf" || input == "+inf")
            return (input);
        else
            return (input + "f");
    }
    if (type == INT)
    {
        res = static_cast<float>(atoi(input.c_str()));
        ss << res << ".0f";
        return (ss.str());
    }
    if (type == DOUBLE)
    {
        res = static_cast<float>(atof(input.c_str()));
        if (res == static_cast<int>(res))
            ss << res << ".0f";
        else
            ss << res << "f";
        return (ss.str());
    }
    if (type == CHAR)
    {
        res = static_cast<float>(input.c_str()[0]);
        ss << res << ".0f";
        return (ss.str());
    }
    return (ss.str());
}

std::string getDouble(const std::string &input, int type)
{
    double res;
    std::stringstream ss;

    if (type == DOUBLE)
        return (input);
    if (type == SPECIAL)
    {
        if (input == "nan" || input == "inf" || input == "-inf" || input == "+inf")
            return (input);
        else if (input == "nanf")
            return (input.substr(0, input.length() - 1));
        else
            return (input + ".0");
    }
    if (type == INT)
    {
        res = std::atoi(input.c_str());
        ss << static_cast<double>(res) << ".0";
        return (ss.str());
    }
    if (type == FLOAT)
    {
        std::string floatStr = input.substr(0, input.length() - 1);
        res = std::atof(floatStr.c_str());
        if (res == static_cast<int>(res))
            ss << res << ".0";
        else
            ss << res;
        return (ss.str());
    }
    if (type == CHAR)
    {
        res = static_cast<double>(input.c_str()[0]);
        ss << res << ".0";
        return (ss.str());
    }
    return (ss.str());
}

int checkDigitsDotAndF(const std::string &input)
{
    int dot_count = 0;
    int f_count = 0;
	int digit_count = 0;
	int i;

	i = 0;
    while (i < input.length())
    {
        if (isdigit(input[i]))
            digit_count++;
        else if (input[i] == '.')
            dot_count++;
        else if (input[i] == 'f' && isdigit(input[i - 1]))
            f_count++;
        else
            return (-1);
        i++;
    }
    if (dot_count > 1 || f_count > 1 || digit_count == 0)
        return (-1);
    return (0);
}

int isAllDigits(const std::string &input)
{
    unsigned int i;

	i = 0;
    if (input.empty())
        return (-1);
    if (input[0] == '+' || input[0] == '-')
        i = 1;
    if (i == input.length())
        return (-1);
    while (i < input.length())
    {
        if (!isdigit(input[i]))
            return (-1);
        i++;
    }
    return (1);
}

int getType(const std::string &input)
{
    if (input.find('.') != std::string::npos)
    {
		if (checkDigitsDotAndF(input) == -1)
			return (UNDEFINED);
        if (input[input.length() - 1] == '.')
            return (UNDEFINED);
        if (input.find('f') != std::string::npos)
        {
            if (input[input.length() - 1] != 'f')
                return (UNDEFINED);
            return (FLOAT);
        }
        else
            return (DOUBLE);
    }
    else if (input == "nan" || input == "nanf" ||
             input == "-inf" || input == "+inf" || input == "inf")
        return (SPECIAL);
    else if (input.find('f') != std::string::npos)
        return (UNDEFINED);
	else if (isAllDigits(input))
		return (INT);
    else if (input.length() == 1 && isprint(input[0]))
        return (CHAR);
    return (UNDEFINED);
}

void ScalarConverter::convert(const std::string &input)
{   
    int type;

	if (input.empty())
	{
        std::cerr << "Error: Input is empty" << std::endl;
		return ;
	}
    type = getType(input);
    if (type == UNDEFINED)
    {
        std::cerr << "Error: Undefined type for input \"" << input << "\"" << std::endl;
        return ;
    }
    print(getChar(input, type), getInt(input, type), getFloat(input, type), getDouble(input, type));
}