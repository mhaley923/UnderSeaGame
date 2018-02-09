#include <iostream>
using namespace std;
#include "Cave.h"
#include "GameObject.h"
#include "CartPoint.h"
#include "CartVector.h"
#include "CoralReef.h"
#include "Fish.h"


Cave::Cave(): GameObject('c', 0)
{
    space=100;
    updater=0;
    state = 'e';
    cout << "Cave default constructed" << endl;
}

Cave::Cave(int in_id, CartPoint in_loc): GameObject('c', in_id, in_loc)
{
    space=100;
    state = 'e';
    updater=0;
    cout << "Cave constructed" << endl;
}
Cave::~Cave()
{
    cout << "Cave destructed" << endl;
}

bool Cave::hide_fish(Fish* fish_to_hide)
{
    if(fish_to_hide->is_hidden())
        return false;
    if(space-fish_to_hide->get_size()>=0)
    {
        space = space - fish_to_hide->get_size();
        return true;
    }
    //cout << "Can't hide" << endl;
    return false;
    
}

bool Cave::release_fish(Fish* fish_to_release)
{
    if(fish_to_release->is_hidden())
    {   space = space + fish_to_release->get_size();
        return true;    }
    return false;
    
}

bool Cave::update()
{
    if(space==0)
    {
        if(updater==1)
            return false;
        else
        {
            state='p';
            display_code = 'C';
            updater++;
            cout << "Cave " << this->get_id() << " is packed like sardines" <<endl;
            return true;
        }
    }
    else if(space>0)
        return false;
    return false;
   
}

void Cave:: show_status()
{
    cout << "Cave Status: " << display_code << " with ID " << get_id() << " at location " << get_location() << " has a space of " << space << endl;
    
}




