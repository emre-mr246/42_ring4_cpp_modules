#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>

typedef std::string str;

# define RESET "\033[0m"
# define GREEN "\033[42m"
# define RED "\033[41m"

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook();

	void add_contact();
	void search_contact();
	void print_contact_details(int index);
	void display_contacts(int contactCount);

  private:
	static const int max_contacts = 8;
	int contactIndex;
	int contactCount;
	Contact array[max_contacts];

	// PhoneBook Utils
	void print_header();
	str truncate(const str &str);
	bool is_valid_index(const str &input, int index);
};

// UTILS
str	get_input(str input_str);

#endif