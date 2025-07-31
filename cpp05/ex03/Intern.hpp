/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:12:13 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:12:13 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
	Intern(void);
	~Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);

	AForm *makeForm(std::string form, std::string target) const;

	class FormNotFoundException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Intern const &src);

#endif
