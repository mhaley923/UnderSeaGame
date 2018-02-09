#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Cave.h"
#include "CoralReef.h"
#include "Fish.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include <math.h>
using namespace std;

int main()
{
    
    View v = View();
    v.clear();
    Model mod = Model();
    
    char command;
    mod.show_status();
    mod.display(v);
    
    while(command!='q')
    {
    cout << "Enter command: ";
    cin >> command;

    switch(command)
    {
    case 's':
    {
        do_swim_command(mod);
        mod.display(v);
        break;
    }
    case 'e':
    {
        do_eat_command(mod);
        mod.display(v);
        break;
    }
    case 'f':
    {
        do_float_command(mod);
        mod.display(v);
        break;
    }
    case 'z':
    {
        do_zoom_command(mod);
        mod.display(v);
        break;
    }
    case 'g':
    {
        do_go_command(mod);
        //mod.show_status();
        mod.display(v);
        break;
    }
    case 'r':
    {
        do_run_command(mod);
        //mod.show_status();
        mod.display(v);
        break;
    }
    case 'q':
    {
        cout << "Terminating program" << endl;
        break;
    }
    default:
        break;
    }
    }


    
    return 0;
}