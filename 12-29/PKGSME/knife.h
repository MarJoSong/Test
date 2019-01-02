#pragma once
#include <iostream>
#include <string>
#include "weapon.h"

using namespace std;

class Knife:public Weapon
{
public:
    Knife();
    virtual int getBaseDamage();
    virtual int suckBlood();
    virtual bool freeze();
    virtual bool getCrit();
};
