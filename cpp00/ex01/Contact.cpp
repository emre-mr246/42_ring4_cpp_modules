/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:19:14 by emgul             #+#    #+#             */
/*   Updated: 2024/10/10 14:19:45 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() {
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    secret = "";
}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& name) {
    firstName = name;
}

void Contact::setLastName(const std::string& last) {
    lastName = last;
}

void Contact::setNickname(const std::string& nick) {
    nickname = nick;
}

void Contact::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
}

void Contact::setSecret(const std::string& secret) {
    this->secret = secret;
}

std::string Contact::getFirstName() const {
    return (firstName);
}

std::string Contact::getLastName() const {
    return (lastName);
}

std::string Contact::getNickname() const {
    return (nickname);
}

std::string Contact::getPhoneNumber() const {
    return (phoneNumber);
}

std::string Contact::getSecret() const {
    return (secret);
}

