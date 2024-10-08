#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>

typedef std::string str;

#define RESET   "\033[0m"
#define GREEN   "\033[42m"
#define RED     "\033[41m"

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
        str firstName;
        str lastName;
        str nickname;
        str phoneNumber;
        str secret;
};


class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();

        void add_contact();
        void search_contact();

        str truncate(const std::string& str);
        bool is_valid_index(const std::string& ret, int index);
        void print_contact_details(int index);
        void display_contacts(int currentContactCount);

    private:
        static const int max_contacts = 8;
        int currentContactIndex;
        int currentContactCount;
        Contact array[max_contacts];
};

#endif