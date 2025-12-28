
#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy; 
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &copy)
{
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
    value = input * 256.0f;
}

Fixed::Fixed(const float input)
{
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
}

bool 	Fixed::operator!=(const Fixed &other) const
{
    return (this->value != other.getRawBits());
}

bool 	Fixed::operator==(const Fixed &other) const
{
    return (this->value == other.getRawBits());
}

bool 	Fixed::operator<=(const Fixed &other) const
{
    return (this->value <= other.getRawBits());
}

bool 	Fixed::operator>=(const Fixed &other) const
{
    return (this->value >= other.getRawBits());
}

bool 	Fixed::operator<(const Fixed &other) const
{
    return (this->value < other.getRawBits());
}

bool 	Fixed::operator>(const Fixed &other) const
{
    return (this->value > other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->value + other.value);
    return (res);
};

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->value - other.value);
    return (res);
};

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed   &Fixed::operator++(void)
{
    this->value++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed temp(*this);
    this->value++;
    return (temp);
}

const   Fixed   &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
};

const   Fixed   &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
};

Fixed   &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
};

Fixed   &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
};