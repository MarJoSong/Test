#include "dargonword.h"

DargonWord::DargonWord()
{
    this->baseDamage = 20;
    this->weaponName = "ÍÀÁú±¦µ¶";
    suckRate = 20;
    holdRate = 30;
    critRate = 35;
}

int DargonWord::getBaseDamage()
{
    return this->baseDamage;
}

int DargonWord::suckBlood()
{
    if(isTrigger(suckRate))
        return static_cast<int>(this->baseDamage * 0.5);
    return 0;
}

bool DargonWord::freeze()
{
    if(isTrigger(holdRate))
        return true;
    return false;
}

bool DargonWord::getCrit()
{
    if(isTrigger(critRate))
        return true;
    return false;
}

bool DargonWord::isTrigger(int rate)
{
    int num = rand()%100;
    if(num<rate)
        return true;
    return false;
}
