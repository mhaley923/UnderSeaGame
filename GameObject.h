#ifndef _GameObject_
#define _GameObject_
#include <iostream>
#include "CartPoint.h"
using namespace std;

class GameObject{
    
public:
    
    GameObject(char in_code, int in_id);
    
    GameObject(char in_code, int in_id, CartPoint in_loc);
    
    virtual ~GameObject();
    
    CartPoint get_location() const;
    
    int get_id() const;
    
    virtual void show_status();
    
    virtual bool update() = 0;
    
    void drawself(char* grid);
    
protected:
    CartPoint location;
    
    char display_code;
    
    char state;
    
    
private:
    
    int id_num;
    
    
};

#endif