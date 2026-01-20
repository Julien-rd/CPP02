#include "Point.hpp"

Point::Point() {
    Fixed a(0);
    Fixed b(0);
    x = a;
    y = b;
}

Point::Point(const float value_1, const float value_2) {
    Fixed a(value_1);
    Fixed b(value_2);
    x = a;
    y = b;
}

Point::Point(const Point& other) {
    Point k(other.x.toFloat(), other.y.toFloat());
    *this = k;
}

Point::~Point() { 
    // std::cout << "Destructor called" << std::endl; 
}

Point& Point::operator=(const Point& other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    x = other.x;
    y = other.y;
    return *this;
}

Fixed Point:: get_x(){
    return x;
}

Fixed Point:: get_y(){
    return y;
}

