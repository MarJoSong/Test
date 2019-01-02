#include "monster.h"

Monster::Monster()
{
    this->m_Hp = 300;
    this->m_Atk = 70;
    this->m_Def = 40;
    this->m_Hold = false;
    this->m_Name = "比克大魔王";
}

void Monster::Attack(Hero* hr)
{
    if(this->m_Hold)
    {
        cout << "怪物 " << this->m_Name << " 被定身，本回合无法攻击" << endl;
        return;
    }

    int trueDamage = (this->m_Atk-hr->m_Def>0)?(this->m_Atk-hr->m_Def):1;
    hr->m_Hp -= trueDamage;
    cout << "怪物 " << this->m_Name << " 攻击了 " << hr->m_Name << " ,造成了 " << trueDamage << " 点伤害" << endl;
}
