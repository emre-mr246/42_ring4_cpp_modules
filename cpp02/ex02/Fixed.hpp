#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &copy);
	~Fixed();
	bool operator>(const Fixed fixed) const;
	bool operator<(const Fixed fixed) const;
	bool operator>=(const Fixed fixed) const;
	bool operator<=(const Fixed fixed) const;
	bool operator==(const Fixed fixed) const;
	bool operator!=(const Fixed fixed) const;
	float operator+(const Fixed fixed) const;
	float operator-(const Fixed fixed) const;
	float operator*(const Fixed fixed) const;
	float operator/(const Fixed fixed) const;
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(Fixed const &first, Fixed const &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(Fixed const &first, const Fixed &second);
	float toFloat() const;

private:
	int _value;
	static const int _numFracBits;
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &number);

#endif
