#include <iostream>
#include "Fish.h"
#include "CoralReef.h"
#include "Cave.h"
#include "Model.h"
#include "View.h"
using namespace std;

Model::Model()
{
    time=0;
    
    num_objects=7;
    num_fish=2;
    num_caves=2;
    num_reefs=3;
    
    CartPoint p1 = CartPoint(5,1);
    CartPoint p2 = CartPoint(6,2);
    CartPoint p3 = CartPoint(1,20);
    CartPoint p4 = CartPoint(20,1);
    CartPoint p5 = CartPoint(20,20);
    Cave *c1 = new Cave(1,p1);
    Cave *c2 = new Cave(2,p2);
    Fish *f1 = new Fish(1,c1);
    Fish *f2 = new Fish(2,c2);
    CoralReef *r1 = new CoralReef(1,p3);
    CoralReef *r2 = new CoralReef(2,p4);
    CoralReef *r3 = new CoralReef(3,p5);
    
    object_ptrs = new GameObject*[num_objects];
    fish_ptrs = new Fish*[num_fish];
    cave_ptrs = new Cave*[num_caves];
    reef_ptrs = new CoralReef*[num_reefs];
    
    
    fish_ptrs[0] = f1;
    fish_ptrs[1] = f2;
    cave_ptrs[0] = c1;
    cave_ptrs[1] = c2;
    reef_ptrs[0] = r1;
    reef_ptrs[1] = r2;
    reef_ptrs[2] = r3;
    
    object_ptrs[0] = c1;
    object_ptrs[1] = c2;
    object_ptrs[2] = f1;
    object_ptrs[3] = f2;
    object_ptrs[4] = r1;
    object_ptrs[5] = r2;
    object_ptrs[6] = r3;
   
    cout << "Model default constructed" << endl;
}
/*
Model:: ~Model()
{
    for(int i=0; i<num_objects; i++)
        delete object_ptrs[i];
    cout << "Model destructed" << endl;
}*/


Fish* Model::get_Fish_ptr(int id_num) //what if id num is wrong
{
    for(int i = 0; i<num_fish; i++)
        if(fish_ptrs[i]->get_id()==id_num)
            return fish_ptrs[i];
    return NULL;
}

CoralReef* Model::get_CoralReef_ptr(int id_num)
{
    for(int i = 0; i<num_reefs; i++)
        if(reef_ptrs[i]->get_id()==id_num)
            return reef_ptrs[i];
    return NULL;

}
Cave* Model::get_Cave_ptr(int id_num)
{
    for(int i = 0; i<num_caves; i++)
        if(cave_ptrs[i]->get_id()==id_num)
            return cave_ptrs[i];
    return NULL;

}

bool Model::update()
{
    bool temp=false;
    time++;
    for(int i=0; i<num_objects; i++)
    {
        if(object_ptrs[i]->update()==true){
            temp= true;
        }
    }
    if(temp==true)
        return true;
    return false;
    
}

void Model::show_status()
{
    for(int i=0; i<num_objects; i++)
        object_ptrs[i]->show_status();

}

void Model::display(View& view)
{
    cout << "Time: " << time << endl;
    view.clear();
    for(int i = 0; i<num_objects; i++)
        view.plot(object_ptrs[i]);
    view.draw();
}









