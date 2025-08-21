/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:53 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:33 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
  protected:
	std::string _type;

  public:
	AMateria(void);
	AMateria(const std::string &type);
	virtual ~AMateria();
	AMateria(const AMateria &src);
	AMateria &operator=(const AMateria &src);
	virtual std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
