#ifndef _CartVector_
#define _CartVector_
#include <iostream>
using namespace std;

class CartVector {
    
public:
    
    double x;
    double y;
    CartVector();
    CartVector(double in_x, double in_y);
    
};

CartVector operator*(const CartVector& v1, const double d);

CartVector operator/(const CartVector& v1, const double d);

ostream& operator << (ostream& out, const CartVector& v1);

#endif