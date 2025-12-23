
#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;

		Fixed &operator=(const Fixed &copy);

		bool 	operator!=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>(const Fixed &other) const;

		Fixed 	operator+(const Fixed &other) const;
		Fixed 	operator-(const Fixed &other) const;

		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed   &operator++(void);
		Fixed   operator++(int);

		static	const Fixed   &max(const Fixed &a, const Fixed &b);
		static  const Fixed   &min(const Fixed &a, const Fixed &b);
		static Fixed   &max(Fixed &a, Fixed &b);
		static Fixed   &min(Fixed &a, Fixed &b);
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);

#endif
