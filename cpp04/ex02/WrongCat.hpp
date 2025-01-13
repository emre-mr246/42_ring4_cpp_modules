/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:57 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:09:58 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#pragma once

#include <iostream>
#include "WrongAnimal.hpp"
#include "Brain.hpp"

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
