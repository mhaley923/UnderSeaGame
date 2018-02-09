#include <iostream>
#include "GameObject.h"
#include "CartPoint.h"
#include "View.h"
using namespace std;

int ix, iy;
GameObject::GameObject(char in_code, int in_id)
{
    display_code=in_code;
    id_num=in_id;
    location.x=0;
    location.y=0;
    cout << "GameObject default constructed" << endl;
}
    
GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
    display_code=in_code;
    id_num=in_id;
    location.x=in_loc.x;
    location.y=in_loc.y;
    cout << "GameObject constructed" << endl;
}

GameObject::~GameObject()
{
    cout << "GameObect destructed" << endl;
}

CartPoint GameObject::get_location() const
{
    return location;
}
    
    
int GameObject::get_id() const
{
    return id_num;
}
    
void GameObject::show_status()
{
    cout << display_code << " with ID " << id_num << " at location " << location << endl;
}

void GameObject::drawself(char* grid)
{
    *(grid)= display_code;
    *(grid+1)= char(id_num)+48;
    
    
}
