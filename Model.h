#ifndef _Model_
#define _Model_
#include <iostream>
#include "Fish.h"
#include "CoralReef.h"
#include "Cave.h"
#include "View.h"
using namespace std;

class Model
{
private:
    int time;
    GameObject** object_ptrs;
    int num_objects;
    Fish** fish_ptrs;
    int num_fish;
    Cave** cave_ptrs;
    int num_caves;
    CoralReef** reef_ptrs;
    int num_reefs;
    //Model(const Model &obj);

public:
    Model();
    //~Model();
    Fish* get_Fish_ptr(int id_num);
    CoralReef* get_CoralReef_ptr(int id_num);
    Cave* get_Cave_ptr(int id_num);
    bool update();
    void display(View& view);
    void show_status();
    
};

#endif