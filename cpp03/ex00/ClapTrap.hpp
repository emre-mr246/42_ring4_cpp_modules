#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap(const std::string &name);
	~ClapTrap(void);
	ClapTrap(ClapTrap const &copy);
	ClapTrap &operator=(ClapTrap const &copy);
	void ClapTrap::attack(const std::string& target);
	void ClapTrap::takeDamage(unsigned int amount);
	void ClapTrap::beRepaired(unsigned int amount);

private:
	std::string _name;
	unsigned int _health;
	unsigned int _energy;
	unsigned int _attackDamage;
};



#endif