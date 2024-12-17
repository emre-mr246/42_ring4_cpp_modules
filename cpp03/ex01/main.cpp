#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Emre");
	ScavTrap b(a);
	ScavTrap c;
	c = a;

	a.printStats();
	b.printStats();
	c.printStats();

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
	a.guardGate();
	a.changeGatekeeperMode();
	a.guardGate();
	a.changeGatekeeperMode();
	a.beRepaired(4);
		
	std::cout << std::endl;
	return (0);
}
