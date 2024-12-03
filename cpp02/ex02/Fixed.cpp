#include "Fixed.hpp"

const int Fixed::_numFracBits = 8;

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int _value) : _value(_value << _numFracBits)
{
}

Fixed::Fixed(const float _value) : _value(_value * (1 << this->_numFracBits))
{
}

Fixed::Fixed(const Fixed &number) : _value(number._value)
{
}

Fixed::~Fixed()
{
}

bool Fixed::operator>(const Fixed number) const
{
	return (this->toFloat() > number.toFloat());
}

bool Fixed::operator<(const Fixed number) const
{
	return (this->toFloat() < number.toFloat());
}

bool Fixed::operator>=(const Fixed number) const
{
	return (this->toFloat() >= number.toFloat());
}

bool Fixed::operator<=(const Fixed number) const
{
	return (this->toFloat() <= number.toFloat());
}

bool Fixed::operator==(const Fixed number) const
{
	return (this->toFloat() == number.toFloat());
}

bool Fixed::operator!=(const Fixed number) const
{
	return (this->toFloat() != number.toFloat());
}

float Fixed::operator+(const Fixed number) const
{
	return (this->toFloat() + number.toFloat());
}

float Fixed::operator-(const Fixed number) const
{
	return (this->toFloat() - number.toFloat());
}

float Fixed::operator*(const Fixed number) const
{
	return (this->toFloat() * number.toFloat());
}

float Fixed::operator/(const Fixed number) const
{
	return (this->toFloat() / number.toFloat());
}

Fixed Fixed::operator++()
{
	++this->_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	--this->_value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}

float Fixed::toFloat() const
{
	return ((float)_value / (1 << this->_numFracBits));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &number)
{
	ostream << number.toFloat();
	return (ostream);
}
