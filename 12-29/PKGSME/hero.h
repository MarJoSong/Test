#pragma once
#include <iostream>
#include <string>
#include "weapon.h"
#include "monster.h"

using namespace std;

class Monster;

class Hero
{
public:
    Hero();
    void equipWeapon(Weapon* wp);
    void Attack(Monster* mt);


    string m_Name;
    int m_Atk;
    int m_Def;
    int m_Hp;
    Weapon* weapon;
};
