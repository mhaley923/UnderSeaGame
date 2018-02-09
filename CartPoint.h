#ifndef _CartPoint_
#define _CartPoint_
#include "CartVector.h"
#include <iostream>
using namespace std;

class CartPoint {
    
public:
    double x;
    double y;
    CartPoint();
    CartPoint(double in_x, double in_y);
    
};

double cart_distance(CartPoint, CartPoint);

ostream& operator<<(ostream& out, const CartPoint& p1);
CartPoint operator+(const CartPoint& p1, const CartVector& v1);
CartVector operator-(const CartPoint& p1, const CartPoint& p2);

#endif