#include "Vessel.hpp"

int	main(int ac, char **av)
{
	Vessel ves;

	if (ac != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	ves.complain(av[1]);
	return (0);
}