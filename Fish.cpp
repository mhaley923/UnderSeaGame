#include <iostream>
using namespace std;
#include "Fish.h"
#include "CoralReef.h"
#include "Cave.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include <math.h>

Fish::Fish(): GameObject('F', 0)
{
    energy=15;
    size=10;
    prefeast_size=10;
    destination = CartPoint();
    reef = NULL;
    home=NULL;
    state = 'h';
    cout << "Fish default constructed" << endl;
}
Fish::Fish(int in_id, Cave* home): GameObject('F', in_id, home->get_location())
{
    energy=15;
    size=10;
    prefeast_size=10;
    destination = CartPoint();
    reef = NULL;
    this->home=home;
    home->hide_fish(this);
    state = 'h';
    cout << "Fish constructed" << endl;
}

Fish::~Fish()
{
    cout << "Fish destructed" << endl;
}

double Fish::get_size() const
{
    return size;
}

double Fish::get_speed() const
{
    double temp =(1/size)*energy*5;
    return temp;
}

void Fish::setup_destination(CartPoint dest)
{
    delta = (dest-get_location())*(get_speed()/cart_distance(dest,get_location()));
    //cout << "Delta: " << delta << endl;
 
    destination =dest;
    //cout << "Destinaton: " << destination << endl;
    
    
}
void Fish::start_swimming(CartPoint dest)
{
    if(this->is_hidden())
        home->release_fish(this);
    
    setup_destination(dest);
    state='s';

    cout << "Swimming " << get_id() << " to " << destination << endl;
    cout << display_code << get_id() << ": On my way" << endl;
    
}

bool Fish::update_location()
{
    
    
    if((location.x == destination.x) && (location.y == destination.y))
    {
        cout << "I'm there!" << endl;
        return true;
    }
    
    if(fabs(location.x-destination.x)<=fabs(delta.x)&&fabs(location.y-destination.y)<=fabs(delta.y))
    {
        location = destination;
        cout << display_code << get_id() << ": I'm there!" << endl;
        return true;
    }
    
    
    else
    {
        location = location+delta;
        cout << display_code << get_id() << ": Just keep swimming..." << endl;
        return false;
    }
    
}

void Fish::start_eating(CoralReef *destReef)
{
    if(this->is_hidden())
        home->release_fish(this);
    reef=destReef;
    double tsize = 2.0*size;
    setup_destination(reef->get_location());
    cout << "Fish " << get_id() << " eating at CoralReef " << destReef->get_id() << " and returning back to Cave " <<home->get_id() << endl;
    cout << display_code << get_id() << ": Food here I come!" << endl;
    state = 'o';
    
}
void Fish::start_hiding(Cave* destCave)
{
    if(this->is_hidden())
        home->release_fish(this);
    this->home = destCave;
   
    setup_destination(home->get_location());
    state='z';
}

bool Fish::is_hidden()
{
    if(state=='h')
        return true;
    return false;
}

void Fish::float_in_place()
{
    if(this->is_hidden())
        home->release_fish(this);
    
    cout << "Stopping " << get_id() << endl;
    cout << display_code << get_id() << ": Resting my fins" << endl;

    state = 'f';
    
}

//state transitions, return true
bool Fish::update()
{
    
    switch(state)
    {
        case 'f' :
        {
            break;
        }
        case 's' :
        {
            if(update_location()==true)
            {
                //cout << "loc " << location << endl;
                state='f';
                //show_status();
                return true;
            }
            break;
        }
        case 'o' :
        {
            
            if(update_location()==true)
            {
                state='e';
                cout << display_code << get_id() << ": Starting to dine at a coral reef" << endl;
                size = prefeast_size;
                //show_status();
                return true;
            }
            
            break;
        }
        case 'e' :
        {
            
            
            if(reef->is_empty()&&size<(prefeast_size*2.0))
            {
                cout << display_code << get_id() << ": This reef has no more food for me..." << endl;
                state='f';
                
                return true;
            }
            else
            {
                
                
                if(size>=(prefeast_size*2.0))
                {
                    prefeast_size=size;
                    
                    setup_destination(this->home->get_location());
                    cout << display_code << get_id() << ": I'm full. I'm heading home" << endl;
                    
                    state='z';
                    return true;
                }
                else
                {

                if(reef->get_amount()<20)
                    size+= reef->provide_food(reef->get_amount())/2;
                else
                    size+= reef->provide_food()/2;
                    
                cout << display_code << get_id() << ": Grew to size " << size << endl;
                

                }
                
            }
      
            
            break;
        }
      
        case 'z' :
        {
            /*if(this->get_location().x==reef->get_location().x)
                cout << display_code << get_id() << ": I'm full: I'm heading home" << endl;*/

            if(this->update_location())
            {
                if(home->hide_fish(this)==true)
                {
                    state='h';
                    cout << display_code << get_id() << ": I am hidden and safe" << endl;
                    return true;
                }
                else
                {
                    state='p';
                    cout << display_code << get_id() << ": Help! My home is full" << endl;
                    return true;
                }
            }
            
            break;
        }
        case 'h' : //needs to checked if it was hidden itself?
        {
            break;
        }
        case 'p' :
        {
            break;}
        default :
        {
            break;
        }
            
    }
    return false;
            
}

void Fish::show_status()
{
    switch(state)
    {
        case 'f':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " is floating. Has a size of: " << get_size() << " and energy of: " << energy << endl;

            break;
        }
        case 's':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " has a speed of: " << get_speed() << " and is heading to: " <<destination<<endl;

            break;
        }
        case 'o':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " is outbound to Reef: " << reef->get_id() << " with a speed of " << get_speed() << endl;

            break;
        }
        case 'e':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " is eating at Reef " << reef->get_id() << endl;

            break;
        }
        case 'v':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " is eating at Reef " << reef->get_id() << endl;
            
            break;
        }
        case 'z':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " is swimming to Cave " << home->get_id() << " with a speed of " << get_speed() << endl;
            break;
        }
        case 'h':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location()<< " is hidden in Cave " << home->get_id() << endl;
            break;
        }
        case 'p':
        {
            cout << "Fish status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " is panicked!!!! And has a size of " << get_size() << endl;

            break;
        }
        default:
        {
            cout << "dufault" << endl;
            break;
        }
    }
}




