/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:08 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	meta->makeSound();
	delete (meta);
	std::cout << std::endl;

	Animal *d = new Dog();
	d->makeSound();

	delete (d);
	std::cout << std::endl;

	const Animal *c = new Cat();
	c->makeSound();
	delete (c);
	std::cout << std::endl;

	const WrongAnimal *w = new WrongCat();
	w->makeSound();
	delete (w);

	return (0);
}
