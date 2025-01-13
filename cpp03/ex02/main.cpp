/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:48 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:11:49 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap a("Emre");
	FragTrap b(a);
	FragTrap c;
	c = a;

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
	a.highFivesGuys();
	b.highFivesGuys();
	c.highFivesGuys();

	std::cout << std::endl;
	a.printStats();
	b.printStats();
	c.printStats();
		
	std::cout << std::endl;
	return (0);
}
