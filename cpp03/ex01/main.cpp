#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Emre");

	a.guardGate();
	a.changeGatekeeperMode();
	a.guardGate();
	a.beRepaired(4);
}