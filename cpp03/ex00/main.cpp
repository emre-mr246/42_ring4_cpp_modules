#include "ClapTrap.hpp"

int main()
{
	ClapTrap emre("Emre");
	ClapTrap hakan(emre);
	ClapTrap beril;

	beril = emre;

	emre.takeDamage(5);
	emre.takeDamage(5);
	emre.beRepaired(3);
	emre.beRepaired(123);
	emre.attack("Hakan");

	hakan.takeDamage(3);
	
	beril.attack("Hakan");
	beril.beRepaired(3);
	return (0);
}