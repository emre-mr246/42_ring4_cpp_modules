#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

typedef std::string str;

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();

        void add_contact();
        void search_contact();

    private:
        static const int max_contacts = 8;
        int currentContactIndex;
        int currentContactCount;
        Contact array[max_contacts];
};

class	Contact {
	public:
		Contact();
		~Contact();

		void	setFirstName(const str& name);
		void	setLastName(const str& last);
		void	setNickname(const str& nick);
		void	setPhoneNumber(const str& phone);
		void	setSecret(const str& secret);
		str		getFirstName() const;
		str		getLastName() const;
		str		getNickname() const;
		str		getPhoneNumber() const;
		str		getSecret() const;

	private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string secret;
};

#endif