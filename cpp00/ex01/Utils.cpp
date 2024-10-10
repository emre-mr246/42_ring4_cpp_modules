/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 01:03:51 by emgul             #+#    #+#             */
/*   Updated: 2024/10/10 15:26:24 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <cctype>

bool is_valid_input(const std::string& str)
{
    size_t i;

    if (str.empty()) 
        return (false);
    i = 0;
    while (i < str.length())
    {
        char c = str[i];
        if (!std::isalnum(c) && c != ' ')
            return (false);
        i++;
    }
    return (true);
}

str get_input(str input_str)
{
	str line;

	std::cout << input_str;
	std::getline(std::cin, line);
	while (line.empty() || !is_valid_input(line)) {        
		system("clear");
		std::cout << "Invalid input. Please try again." << std::endl;
		sleep(1);
    	system("clear");
		std::cout << input_str;
		std::getline(std::cin, line);
    }
	return (line);
}

str PhoneBook::truncate(const str &str)
{
    if (str.length() > 9)
        return (str.substr(0, 9) + ".");
    return (str);
}

bool PhoneBook::is_valid_index(const str &input, int index)
{
	return (!(index < 0 || index >= contactCount || (index == 0 && input[0] != '0')));
}
