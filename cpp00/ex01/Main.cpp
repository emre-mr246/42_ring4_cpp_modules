/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:46:27 by emgul             #+#    #+#             */
/*   Updated: 2024/10/10 15:43:58 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <string>
#include <unistd.h>

int	main(void)
{
	PhoneBook PhoneBook;

	str line;

	system("clear");
	std::cout << "Welcome to Watermelon Contact Manager!" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Commands: ADD, SEARCH and EXIT" << std::endl;
		line = get_input("Input: ");
		if (!line.compare("ADD"))
			PhoneBook.add_contact();
		else if (!line.compare("SEARCH"))
			PhoneBook.search_contact();
		else if (!line.compare("EXIT"))
		{
			system("clear");
			std::cout << "See you soon! ツ" << std::endl;
			sleep(1);
			return (0) ;
		}
		system("clear");
	}
	return (-1);
}
