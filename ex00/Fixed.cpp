/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:39:20 by jromann           #+#    #+#             */
/*   Updated: 2026/01/20 17:29:31 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0) {
    std::cout << "Default constructor called" << std::endl;
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

