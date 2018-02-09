#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include <math.h>

using namespace std;

CartPoint::CartPoint()
{
    x=0.0;
    y=0.0;
}

CartPoint::CartPoint(double in_x, double in_y)
{
    x=in_x;
    y=in_y;
}
ostream& operator << (ostream& out, const CartPoint& p1)
{
    out << "(" << p1.x << "," << p1.y << ")";
    return out;
}

CartPoint operator+(const CartPoint& p1, const CartVector& v1)
{
    CartPoint p0;
    p0.x=p1.x+v1.x;
    p0.y=p1.y+v1.y;
    return p0;
}

CartVector operator-(const CartPoint& p1, const CartPoint& p2)
{
    CartVector v0;
    v0.x=p1.x-p2.x;
    v0.y=p1.y-p2.y;
    return v0;
}

double cart_distance(CartPoint p1, CartPoint p2)
{
    double d = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
    return d;
}
