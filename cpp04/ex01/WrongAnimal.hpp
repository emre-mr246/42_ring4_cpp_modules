/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:24 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:25 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once

#include <iostream>

class WrongAnimal
{
  public:
    WrongAnimal(void);
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal &operator=(const WrongAnimal &src);
    void makeSound(void) const;

  protected:
    std::string _type;
};

#endif
