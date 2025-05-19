#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);

		Fixed(const int value);
		Fixed(const float value);

		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator/(const Fixed &other);
		Fixed operator*(const Fixed &other);


		Fixed &operator++(); // ++var
		Fixed operator++(int); // var++
		Fixed &operator--();
		Fixed operator--(int);

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

	private:
		int _value;
		static const int _fractionalBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
