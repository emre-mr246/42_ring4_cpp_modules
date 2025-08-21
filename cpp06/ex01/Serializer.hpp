/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:31 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string intraLogin;
	std::string moduleName;
	int grade;
};

class Serializer
{
  private:
	Serializer(void);
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif
