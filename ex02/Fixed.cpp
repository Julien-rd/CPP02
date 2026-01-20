#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const int value){
    std::cout << "Int constructor called" << std::endl;
    fixed_point = value << frac_bits;
}

Fixed::Fixed(const float value){
    std::cout << "Float constructor called" << std::endl;
    fixed_point = roundf(value * (1 << frac_bits));
} 

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    fixed_point = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
            fixed_point = other.getRawBits();
        return *this;
}

bool Fixed::operator==(const Fixed& other) {
    if (this == &other)
        return 1;
    return 0;
}

bool Fixed::operator<(const Fixed& other){
    if (this < &other)
        return 1;
    return 0;
}

bool Fixed::operator>(const Fixed& other){
    if (this > &other)
        return 1;
    return 0;
}

bool Fixed::operator>=(const Fixed& other){
    if (this >= &other)
        return 1;
    return 0;
}

bool Fixed::operator<=(const Fixed& other){
    if (this <= &other)
        return 1;
    return 0;
}

bool Fixed::operator!=(const Fixed& other){
    if (this != &other)
        return 1;
    return 0;
}

Fixed& Fixed::operator++() {
    fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    fixed_point++;
    return temp;
}

Fixed& Fixed::operator--() {
    fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    fixed_point++;
    return temp;
}

float Fixed::operator+(const Fixed& other){
    return (this->toFloat() + other.toFloat()); }

float Fixed::operator-(const Fixed& other){ 
    return (this->toFloat() - other.toFloat()); }

float Fixed::operator*(const Fixed& other){ 
    return (this->toFloat() * other.toFloat()); }

float Fixed::operator/(const Fixed& other){ 
    return (this->toFloat() / other.toFloat()); }

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    if (first < second)
        return first;
    return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    if (first.toFloat() < second.toFloat())
        return first;
    return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    if (first > second)
        return first;
    return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    if (first.toFloat() > second.toFloat())
        return first;
    return second;
}


int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point; }

void Fixed::setRawBits(int const raw) { fixed_point = raw; }

float Fixed::toFloat( void ) const { return (float)fixed_point / (1 << frac_bits) ; }

int Fixed::toInt( void ) const { return fixed_point >> frac_bits ; }

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
