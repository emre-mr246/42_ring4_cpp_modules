/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:19:14 by emgul             #+#    #+#             */
/*   Updated: 2024/10/10 17:03:51 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    secret = "";
}

Contact::~Contact()
{
}

void Contact::setFirstName(const std::string &firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setSecret(const std::string &secret)
{
    this->secret = secret;
}

const str &Contact::getFirstName() const
{
    return (firstName);
}

const str &Contact::getLastName() const
{
    return (lastName);
}

const str &Contact::getNickname() const
{
    return (nickname);
}

const str &Contact::getPhoneNumber() const
{
    return (phoneNumber);
}

const str &Contact::getSecret() const
{
    return (secret);
}
