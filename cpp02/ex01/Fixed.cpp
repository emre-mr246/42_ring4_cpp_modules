#include "Fixed.hpp"

const int Fixed::_numFracBits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _value) : _value(_value << _numFracBits)
{
    std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float _value) : _value(_value * (1 << this->_numFracBits))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &point) : _value(point._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &point)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = point._value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat() const
{
    return (float)_value / (1 << this->_numFracBits);
}

int Fixed::toInt() const
{
    return _value >> this->_numFracBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &point)
{
    os << point.toFloat();
    return os;
}
