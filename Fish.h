#ifndef _Fish_
#define _Fish_
#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "CoralReef.h"
#include "Cave.h"
#include "GameObject.h"
using namespace std;

class Cave;
class Fish: public GameObject
{
public:
    Fish();
    Fish(int in_id, Cave* home);
    ~Fish();
    bool update();
    double get_size() const;
    void start_swimming(CartPoint dest);
    void start_eating(CoralReef* destReef);
    bool is_hidden();
    void start_hiding(Cave* destCave);
    void float_in_place();
    void show_status();
    double get_speed() const;
    
private:
    double energy;
    double size;
    double prefeast_size;
    CartPoint destination;
    CartVector delta;
    CoralReef* reef;
    Cave* home;
    bool update_location();
    void setup_destination(CartPoint dest);
};


#endif