/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:32 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:09:33 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria *_inventory[4];

public:
	MateriaSource(void);
	~MateriaSource();
	MateriaSource(const MateriaSource &src);
	MateriaSource &operator=(const MateriaSource &src);
	void learnMateria(AMateria *materia);
	AMateria* createMateria(std::string const & type);
	void getInventory();
};

#endif
