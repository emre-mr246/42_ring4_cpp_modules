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
	a.attack("Hakan");
	a.attack("Hakan");
	a.takeDamage(12);
	a.printStats();
	a.beRepaired(1);
	a.printStats();

	std::cout << std::endl;
	b.attack("Hakan");
	b.attack("Hakan");
	b.takeDamage(35);
	b.printStats();
	b.beRepaired(2);
	b.printStats();
	
	std::cout << std::endl;
	c.attack("Hakan");
	c.attack("Hakan");
	c.takeDamage(52);
	c.printStats();
	c.beRepaired(3);
	c.printStats();

	std::cout << std::endl;
	a.guardGate();
	a.changeGatekeeperMode();
	a.guardGate();
	a.changeGatekeeperMode();
	a.printStats();

	std::cout << std::endl;
	a.printStats();
	b.printStats();
	c.printStats();
		
	std::cout << std::endl;
	return (0);
}
