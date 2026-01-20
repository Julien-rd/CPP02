/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:39:17 by jromann           #+#    #+#             */
/*   Updated: 2026/01/20 17:04:04 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

    private:

    int fixed_point;
    static const int frac_bits = 8;

    public:

    Fixed();
    ~Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif
