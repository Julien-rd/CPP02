#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

    private:

    int fixed_point;
    static const int frac_bits = 8;

    public:

    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    Fixed(const Fixed& other);

    Fixed& operator=(const Fixed& other);
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    bool operator==(const Fixed& other);
    bool operator<(const Fixed& other);
    bool operator>(const Fixed& other);
    bool operator>=(const Fixed& other);
    bool operator<=(const Fixed& other);
    bool operator!=(const Fixed& other);
    float operator+(const Fixed& other);
    float operator-(const Fixed& other);
    float operator*(const Fixed& other);
    float operator/(const Fixed& other);

    static Fixed& min(Fixed& first, Fixed& second);
    static const Fixed& min(const Fixed& first, const Fixed& second);
    static Fixed& max(Fixed& first, Fixed& second);
    static const Fixed& max(const Fixed& first, const Fixed& second);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};


std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif
