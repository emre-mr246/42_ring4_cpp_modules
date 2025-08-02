/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:13 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#pragma once

#include <iostream>
#include "Data.hpp"
#include <stdint.h>


class Serializer
{
	private:
		Serializer(void);
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
