/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:23 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:24 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#pragma once

#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
  public:
    WrongCat(void);
    ~WrongCat();
    WrongCat(const WrongCat &src);
    WrongCat &operator=(const WrongCat &src);
    void makeSound(void) const;

  private:
    Brain *_brain;
};

#endif
