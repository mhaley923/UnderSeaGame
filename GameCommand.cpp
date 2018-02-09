#include <iostream>
#include "GameCommand.h"
#include "Fish.h"
#include "CartPoint.h"
#include "GameObject.h"
#include "Model.h"
using namespace std;

void do_swim_command(Model &model)
{
    int ID, xx, yy;
    cin >> ID;
    cin >> xx;
    cin >> yy;
    CartPoint temp = CartPoint(xx,yy);
    (model.get_Fish_ptr(ID))->start_swimming(temp);
    
}

void do_eat_command(Model &model)
{
    int ID1, ID2;
    cin >> ID1;
    cin >> ID2;
    (model.get_Fish_ptr(ID1))->start_eating(model.get_CoralReef_ptr(ID2));
    
}
void do_float_command(Model &model)
{
    int ID;
    cin >> ID;
    (model.get_Fish_ptr(ID))->float_in_place();
}
void do_zoom_command(Model &model)
{
    int ID1, ID2;
    cin >> ID1;
    cin >> ID2;
    cout << "Fish " << model.get_Fish_ptr(ID1)->get_id() << " swimming to Cave " <<model.get_Cave_ptr(ID2)->get_id() << endl;
    
    cout << "F" << model.get_Fish_ptr(ID1)->get_id() << ": Off to safety" <<endl;
    
    (model.get_Fish_ptr(ID1))->start_hiding(model.get_Cave_ptr(ID2));
    
}
void do_go_command(Model &model)
{   cout << "Advancing one tick" << endl;
    model.update();
    model.show_status();
}
void do_run_command(Model &model)
{
    cout << "Advancing to next event" << endl;
    int i = 0;
    while(model.update()==false)
    {
        i++;
        if(i==5)
            break;
    }
    model.show_status();
        
}
