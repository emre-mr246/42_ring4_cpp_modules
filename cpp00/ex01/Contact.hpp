#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

typedef std::string str;

class	Contact {
	public:
		Contact();
		~Contact();

		str		getFirstName() const;
		str		getLastName() const;
		str		getNickname() const;
		str		getPhoneNumber() const;
		str		getSecret() const;
		void	setFirstName(const str& name);
		void	setLastName(const str& last);
		void	setNickname(const str& nick);
		void	setPhoneNumber(const str& phone);
		void	setSecret(const str& secret);

	private:
        str firstName;
        str lastName;
        str nickname;
        str phoneNumber;
        str secret;
};

#endif