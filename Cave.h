#ifndef _Cave_
#define _Cave_
#include <iostream>
#include "CartPoint.h"
#include "GameObject.h"
#include "Fish.h"
using namespace std;

class Fish;
class Cave: public GameObject
{
public:
    Cave();
    ~Cave();
    Cave(int in_id, CartPoint in_loc);
    bool hide_fish(Fish* fish_to_hide);
    bool release_fish(Fish* fish_to_release);
    bool update();
    void show_status();
   
    
    
private:
    double space;
    int updater;
};


#endif