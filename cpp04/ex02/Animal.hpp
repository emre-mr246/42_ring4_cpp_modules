/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:18 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:19 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#include <iostream>

class Animal
{
public:
	virtual ~Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual void makeSound(void) const = 0;

protected:
	Animal(void);
	std::string _type;
};

#endif
