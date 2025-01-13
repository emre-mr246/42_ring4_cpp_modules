/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:11:04 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:11:05 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	~Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	void makeSound(void) const;
};

#endif
