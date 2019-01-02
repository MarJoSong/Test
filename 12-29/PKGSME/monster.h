#pragma once
#include <iostream>
#include <string>
#include "weapon.h"
#include "hero.h"

using namespace std;

class Hero;

class Monster
{
public:
    Monster();
    string m_Name;
    int m_Atk;
    int m_Def;
    int m_Hp;
    bool m_Hold;
    void Attack(Hero* hr);
};
