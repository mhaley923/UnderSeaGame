#include <iostream>
#include "CartVector.h"
#include <math.h>
using namespace std;

CartVector::CartVector()
{
    x=0.0;
    y=0.0;
}

CartVector::CartVector(double in_x, double in_y)
{
    x=in_x;
    y=in_y;
}

ostream& operator << (ostream& out, const CartVector& v1)
{
    out << "<" << v1.x << "," << v1.y << ">";
    return out;
}


CartVector operator*(const CartVector& v1, const double d)
{
    CartVector v;
    v.x=v1.x*d;
    v.y=v1.y*d;
    return v;
}

CartVector operator/(const CartVector& v1, const double d)
{
    CartVector v;
    v.x=double(v1.x)/d;
    v.y=double(v1.y)/d;
    return v;
}