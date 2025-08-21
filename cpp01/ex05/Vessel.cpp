/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vessel.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:34 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:36 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vessel.hpp"

Vessel::Vessel(void)
{
	std::cout << "Prepare for launch! Our starship is ready to embark on its "
	             "cosmic journey!"
	          << std::endl;
}

Vessel::~Vessel(void)
{
	std::cout << "Mission accomplished! Our starship has completed its cosmic "
	             "journey and is returning to base!"
	          << std::endl;
}

void Vessel::debug(void)
{
	std::cout
	    << "Debug: Our journey must be free of dangers and filled with wonders!"
	    << std::endl;
}

void Vessel::info(void)
{
	std::cout << "Info: Pirate activity has been reported in this sector."
	          << std::endl;
}

void Vessel::warning(void)
{
	std::cout
	    << "Warning: Increased pirate presence detected! Proceed with caution."
	    << std::endl;
}

void Vessel::error(void)
{
	std::cout << "Error: A pirate vessel has breached our defenses! Engage "
	             "evasive maneuvers!"
	          << std::endl;
}

void Vessel::complain(std::string level)
{
	void (Vessel::*ptrComplain[4])(void) = {&Vessel::debug, &Vessel::info,
	                                        &Vessel::warning, &Vessel::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*ptrComplain[i])();
			return;
		}
		i++;
	}
}
