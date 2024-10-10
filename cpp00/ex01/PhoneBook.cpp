/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:05:30 by emgul             #+#    #+#             */
/*   Updated: 2024/10/10 15:46:51 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

PhoneBook::PhoneBook() : contactIndex(0), contactCount(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
	str line;
	
    if (this->contactCount < this->max_contacts)
	{
        this->contactCount++;
	}
	this->contactIndex++;
	if (this->contactIndex >= this->contactCount)
	{
    	contactIndex = 0;
	}
	system("clear");
	line = get_input("Type a name: ");
	this->array[this->contactIndex].setFirstName(line);
	line = get_input("Type a surname: ");
	this->array[this->contactIndex].setLastName(line);
	line = get_input("Type a nickname: ");
	this->array[this->contactIndex].setNickname(line);
	line = get_input("Type a phone number: ");
	this->array[this->contactIndex].setPhoneNumber(line);
	line = get_input("Type a dark secret: ");
	this->array[this->contactIndex].setSecret(line);
    system("clear");
}

void PhoneBook::print_contact_details(int i)
{
	std::cout << "Name: " << this->array[i].getFirstName() << std::endl;
	std::cout << "Lastname: " << this->array[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->array[i].getNickname() << std::endl;
	std::cout << "Phone number: " << this->array[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->array[i].getSecret() << std::endl;
}

void PhoneBook::print_header()
{
	std::cout << RED 
	<< std::setw(5) << "Index" << "|" 
	<< std::setw(10) << "Firstname" << "|"
	<< std::setw(10) << "Lastname" << "|"
	<< std::setw(10) << "Nickname" << "|"
	<< RESET << std::endl;
}

void PhoneBook::display_contacts(int contactCount)
{
	int i;

	print_header();
	i = 0;
	while (i < contactCount)
	{
		std::cout << GREEN << std::setw(5) << i << "|"
		<< std::setw(10) << truncate(array[i].getFirstName()) << "|"
		<< std::setw(10) << truncate(array[i].getLastName()) << "|" 
		<< std::setw(10) << truncate(array[i].getNickname()) << "|" 
		<< RESET << std::endl;
		i++;
	}
}

void PhoneBook::search_contact()
{
	str line;
	int	i;

	system("clear");
	if (this->contactCount == 0)
	{
		std::cout << "There are no contacts here." << std::endl;
		sleep(1);
		return ;
	}
	display_contacts(contactCount);
	std::cout << std::endl;
	line = get_input("Type a index: ");
	i = atoi(line.c_str());
	if (!is_valid_index(line, i))
	{
		std::cout << "Invalid input!" << std::endl;
		sleep(1);
		return ;
	}
	system("clear");
	print_contact_details(i);
	std::cout << std::endl << "Press a key to continue..." << std::endl;
	getchar();
}
