/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_new.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:30:23 by jromann           #+#    #+#             */
/*   Updated: 2026/01/20 18:35:16 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0) {
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

bool Fixed::operator==(const Fixed& other) const {
    return fixed_point == other.fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const {
    return fixed_point != other.fixed_point;
}

bool Fixed::operator<(const Fixed& other) const {
    return fixed_point < other.fixed_point;
}

bool Fixed::operator>(const Fixed& other) const {
    return fixed_point > other.fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const {
    return fixed_point <= other.fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const {
    return fixed_point >= other.fixed_point;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
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
    fixed_point--;
    return temp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    return (first < second) ? first : second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    return (first < second) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    return (first > second) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    return (first > second) ? first : second;
}

int Fixed::getRawBits(void) const {
    return fixed_point;
}

void Fixed::setRawBits(int const raw) { 
    fixed_point = raw; 
}

float Fixed::toFloat(void) const { 
    return (float)fixed_point / (1 << frac_bits); 
}

int Fixed::toInt(void) const { 
    return fixed_point >> frac_bits; 
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}