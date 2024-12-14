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
