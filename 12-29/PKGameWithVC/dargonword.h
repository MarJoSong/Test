#pragma once
#include <iostream>
#include <string>
#include "weapon.h"

using namespace std;

class DargonWord:public Weapon
{
public:
    DargonWord();
    virtual int getBaseDamage();
    virtual int suckBlood();
    virtual bool freeze();
    virtual bool getCrit();
    bool isTrigger(int rate);

    int suckRate;
    int holdRate;
    int critRate;


};
