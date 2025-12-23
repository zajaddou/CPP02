
#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; 
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

Fixed::Fixed(const int input)
{
    std::cout << "Int constructor called" << std::endl;
    value = input * 256.0f;
}

Fixed::Fixed(const float input)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(input * 256.0f);
}

float 	Fixed::toFloat( void ) const
{
    return (this->value / 256.0f);
}

int 	Fixed::toInt( void ) const
{
    return (this->value / 256.0f);
}

std::ostream & operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return (o);
};


