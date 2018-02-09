#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "View.h"

using namespace std;

View::View()
{
    size=11;
    scale=2.0;
    origin = CartPoint(0,0);
}

void View::clear()
{
    for(int i = 0; i< view_maxsize; i++)
    {
        for(int j = 0; j< view_maxsize; j++)
        {
            grid[i][j][0]='.';
            grid[i][j][1]=' ';
        }
    }
    
        
}

bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
    ix= (location.x-origin.x)/scale;
    iy= (location.y-origin.y)/scale;

    
    if(ix>size || iy>size || ix<0 || iy<0)
    {
        return false;
        cout << "An object is outside the display" << endl;
    }
    return true;
}

void View::plot(GameObject* ptr)
{   int ix,iy;
    
    if(get_subscripts(ix, iy, ptr->get_location()))
    {
        if(grid[ix][iy][0]!='.')
        {
            grid[ix][iy][0]='*';
            grid[ix][iy][1]=' ';
        }
        else
            ptr->drawself(grid[ix][iy]);
    }
    else
        cout << "An object is outside the display " << endl;
    
}


void View::draw()
{
    int m = 20;
    for(int i = size-1; i>=0; i--)
    {
        if(m%4==0 && m<10)
        {
            cout << m << " ";
            
        }

        else if(m%4==0)
        {
            cout << m;
            
        }
        else
            cout << "  ";
        for(int j = 0; j<size; j++)
        {
            cout << grid[j][i][0] << grid[j][i][1];
            
        }
        cout << endl;
         m-=2;
    }
    
    cout << "  0   4   8   12  16  20" << endl;
    
        
}



