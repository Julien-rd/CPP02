/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:38:00 by jromann           #+#    #+#             */
/*   Updated: 2026/01/20 18:38:02 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0) {
    std::cout << "Default constructor called" << std::endl;
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
