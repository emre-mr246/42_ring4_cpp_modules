/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:51:19 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:32 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

typedef std::string str;

class Contact
{
  public:
	Contact();
	~Contact();

	const str &getFirstName() const;
	const str &getLastName() const;
	const str &getNickname() const;
	const str &getPhoneNumber() const;
	const str &getSecret() const;
	void setFirstName(const str &firstName);
	void setLastName(const str &lastName);
	void setNickname(const str &nickname);
	void setPhoneNumber(const str &phoneNumber);
	void setSecret(const str &secret);

  private:
	str firstName;
	str lastName;
	str nickname;
	str phoneNumber;
	str secret;
};

#endif