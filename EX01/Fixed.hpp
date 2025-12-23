#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 			 value;
		static const int bits = 8;

	public:
		Fixed();
		~Fixed();
		
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed &copy);

		Fixed &operator=(const Fixed &copy);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);

#endif
