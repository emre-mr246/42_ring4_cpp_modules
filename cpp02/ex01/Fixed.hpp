/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:03 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:13:05 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
  public:
    Fixed();
    Fixed(const int number);
    Fixed(const float number);
    Fixed(Fixed const &copy);
    ~Fixed();
    Fixed &operator=(const Fixed &src);
    int getRawBits() const;
    void setRawBits(const int raw);
    float toFloat() const;
    int toInt() const;

  private:
    int _value;
    static const int _numFracBits;
};

std::ostream &operator<<(std::ostream &ostream, Fixed const &number);

#endif
