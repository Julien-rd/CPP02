#include "Point.hpp"
#include <iostream>

int main( int argc, char **argv ) {

if (argc != 3)
    return 1;
Point a(2, 0);
Point b(4, 0);
Point c(0, 3);
Point d(atoi(argv[1]), atoi(argv[2]));


bsp(a, b ,c, d);
return 0;
}