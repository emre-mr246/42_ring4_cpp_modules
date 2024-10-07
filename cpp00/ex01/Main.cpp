/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:46:27 by emgul             #+#    #+#             */
/*   Updated: 2024/10/08 02:30:32 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

int	main(void)
{
	PhoneBook PhoneBook;

	str line;
	str add = "ADD";
	str search = "SEARCH";
	str exit = "EXIT";

	system("clear");
	std::cout << "Welcome to Watermelon Contact Manager!" << std::endl;
	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT: ";
		std::getline(std::cin, line);
		if (!line.compare(add))
			PhoneBook.add_contact();
		else if (!line.compare(search))
			PhoneBook.search_contact();
		else if (!line.compare(exit))
		{
			std::cout << "See you soon! ツ" << std::endl;
			break ;
		}
		system("clear");
	}
	sleep(1);
	return (0);
}
