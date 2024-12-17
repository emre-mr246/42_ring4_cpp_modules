#include "FragTrap.hpp"

int main()
{
	FragTrap a("Emre");
	FragTrap b(a);
	FragTrap c;
	c = a;

	std::cout << std::endl;
	a.takeDamage(12);
	a.beRepaired(3);
	a.beRepaired(123);
	a.attack("Hakan");

	std::cout << std::endl;
	b.attack("Hakan");
	b.takeDamage(3);
	
	std::cout << std::endl;
	c.attack("Hakan");
	c.beRepaired(3);

	std::cout << std::endl;
	a.highFivesGuys();
	b.highFivesGuys();
	c.highFivesGuys();
		
	std::cout << std::endl;
	return (0);
}
