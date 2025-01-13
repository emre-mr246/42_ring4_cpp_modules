/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:10:39 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:10:40 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#pragma once

#include <iostream>

class Brain
{
public:
	Brain(void);
	virtual ~Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &src);
	void setIdea(unsigned int i, std::string idea);
	const std::string getIdea(unsigned int i) const;

protected:
	std::string _ideas[100];
};

#endif
