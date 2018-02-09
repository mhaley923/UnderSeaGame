#include <iostream>
using namespace std;
#include "CoralReef.h"
#include "GameObject.h"
#include "CartPoint.h"

//Is there a better way to do this then declaring the parameters?
//char in_code;
//int in_id;

CoralReef::CoralReef(): GameObject('R', 0)
{
    updater=0;
    amount=100;
    state = 'f';
    cout << "CoralReef default constructed" << endl;
}
CoralReef::CoralReef(int in_id, CartPoint in_loc): GameObject('R', in_id, in_loc)
{
    updater=0;
    amount=100;
    state = 'f';
    cout << "CoralReef constructed" << endl;
}
CoralReef::~CoralReef()
{
    cout << "CoralReef destructed" << endl;

}

double CoralReef::get_amount() const
{
    return amount*1.0;
}


bool CoralReef::is_empty()
{
    if(amount==0)
        return true;
    return false;
}

double CoralReef::provide_food(double amount_to_provide)
{
    int temp = amount;
    if(amount>=amount_to_provide)
    {   amount=amount-amount_to_provide;
        return amount_to_provide;
    }
    else
    {
        amount=0;
        //cout << "CoralReef " << this->get_id() << " has been depleted of food" << endl;
        return temp;
    }
        
}
bool CoralReef::update()
{
    
    if(this->is_empty()&&updater==0)
    {
        state='e';
        display_code='r';
        cout << "CoralReef " << this->get_id() << " has been depleted of food" << endl;
        updater++;
        return true;
    }
    else
    {
        return false;
    }
}

void CoralReef::show_status()
{
    cout << "CoralReef Status: " << display_code << " with ID " << this->get_id()
    << " at location " << location << " containing food " << amount << endl;
}








