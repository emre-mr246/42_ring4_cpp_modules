/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:36 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:32 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
  public:
	Cat(void);
	~Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	void makeSound(void) const;
	void newIdea(unsigned int i, std::string idea);
	const std::string getIdea(unsigned int i) const;

  private:
	Brain *_brain;
};

#endif
