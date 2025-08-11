/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:33 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
  public:
    Dog(void);
    ~Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &src);
    void makeSound(void) const;
    void newIdea(unsigned int i, std::string idea);
    const std::string getIdea(unsigned int i) const;

  private:
    Brain *_brain;
};

#endif
