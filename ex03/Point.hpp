/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jromann <jromann@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:10:52 by jromann           #+#    #+#             */
/*   Updated: 2025/12/01 17:27:13 by jromann          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

    private:

    Fixed x;
    Fixed y;

    public:

    Point();
    Point(const float value_1, const float value_2);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    Fixed get_x();
    Fixed get_y();
};

bool bsp( Point a, Point b, Point c, Point point);
std::ostream& operator<<(std::ostream& out, const Point& value);

#endif
