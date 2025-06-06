/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:43 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:44 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#pragma once

#include <iostream>

class Animal
{
public:
	Animal(void);
	virtual ~Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual void makeSound(void) const;

protected:
	std::string _type;
};

#endif
