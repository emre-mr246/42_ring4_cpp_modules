/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:10 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:13:11 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const &copy);
	Fixed &operator=(Fixed const &copy);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _numFracBits;
};

#endif
