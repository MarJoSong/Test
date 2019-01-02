#pragma  once
#include <iostream>
#include <string>
using namespace std;

class Weapon
{
public:
    virtual int getBaseDamage() = 0;
    virtual int suckBlood() = 0;
    virtual bool freeze() = 0;
    virtual bool getCrit() = 0;

    string weaponName;
    int baseDamage;
};

