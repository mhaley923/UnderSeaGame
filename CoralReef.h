#ifndef _CoralReef_
#define _CoralReef_
#include <iostream>
#include "CartPoint.h"
#include "GameObject.h"
using namespace std;

class CoralReef: public GameObject
{
public:
    CoralReef();
    CoralReef(int in_id, CartPoint in_loc);
    ~CoralReef();
    bool is_empty();
    double provide_food(double amount_to_provide = 20.0);
    bool update();
    void show_status();
    double get_amount() const; //added in personally
    
    
private:
    double amount;
    int updater;
};


#endif