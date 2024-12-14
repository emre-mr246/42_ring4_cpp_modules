#include "Fixed.hpp"

const int Fixed::_numFracBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int number)
{
	std::cout << "Integer constructor called" << std::endl;
	this->_value = number << _numFracBits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = number * (1 << this->_numFracBits);
}

Fixed::Fixed(const Fixed &number)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = number._value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &number)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = number._value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << this->_numFracBits));
}

int Fixed::toInt(void) const
{
	return (_value >> this->_numFracBits);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &number)
{
	ostream << number.toFloat();
	return (ostream);
}
