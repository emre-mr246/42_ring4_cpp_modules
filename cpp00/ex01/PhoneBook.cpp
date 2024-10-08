/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:05:30 by emgul             #+#    #+#             */
/*   Updated: 2024/10/08 02:05:56 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

PhoneBook::PhoneBook() : currentContactIndex(0), currentContactCount(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
	std::string name, last, nick, phone, secret;
	system("clear");
	std::cout << "Type a name: ";
	std::getline(std::cin, name);
	std::cout << "Type a surname: ";
	std::getline(std::cin, last);
	std::cout << "Type a nickname: ";
	std::getline(std::cin, nick);
	std::cout << "Type a phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Type a dark secret: ";
	std::getline(std::cin, secret);
	this->array[this->currentContactIndex].setFirstName(name);
	this->array[this->currentContactIndex].setLastName(last);
	this->array[this->currentContactIndex].setNickname(nick);
	this->array[this->currentContactIndex].setPhoneNumber(phone);
	this->array[this->currentContactIndex].setSecret(secret);
	this->currentContactIndex = (this->currentContactIndex + 1) % max_contacts;
	if (currentContactCount < max_contacts)
	{
		currentContactCount++;
	}
	system("clear");
}

std::string PhoneBook::truncate(const std::string &str)
{
	return (str.length() > 9 ? str.substr(0, 9) + "." : str);
}

bool PhoneBook::is_valid_index(const std::string &ret, int index)
{
	return (!(index < 0 || index >= currentContactCount || (index == 0
				&& ret[0] != '0')));
}

void PhoneBook::print_contact_details(int index)
{
	std::cout << "Name: " << this->array[index].getFirstName() << std::endl;
	std::cout << "Lastname: " << this->array[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->array[index].getNickname() << std::endl;
	std::cout << "Phone number: " << this->array[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->array[index].getSecret() << std::endl;
}

void PhoneBook::display_contacts(int currentContactCount)
{
	for (int i = 0; i < currentContactCount; ++i)
	{
		std::cout << GREEN;
		std::cout << std::setw(5) << i << "|";
		std::cout << std::setw(10) << truncate(array[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(array[i].getLastName()) << "|" << std::setw(10)
			<< truncate(array[i].getNickname()) << "|" << RESET << std::endl;
	}
}

void PhoneBook::search_contact()
{
	int	index;

	system("clear");
	if (this->currentContactIndex == 0)
	{
		std::cout << "There are no contacts here." << std::endl;
		sleep(1);
		return ;
	}
	std::cout << RED << std::setw(5) << "Index" << "|" << std::setw(10) << "Firstname"
		<< "|" << std::setw(10) << "Lastname" << "|" << std::setw(10) << "Nickname"
		<< "|" << RESET << std::endl;

	display_contacts(currentContactCount);

	std::cout << std::endl << "Type a index: ";
	std::string ret;
	std::getline(std::cin, ret);
	index = atoi(ret.c_str());
	if (!is_valid_index(ret, index))
	{
		std::cout << "Invalid input!" << std::endl;
		sleep(1);
		return ;
	}
	system("clear");
	print_contact_details(index);
	std::cout << std::endl << "Press a key to continue..." << std::endl;
	getchar();
}
