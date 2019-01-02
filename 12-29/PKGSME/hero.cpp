#include "hero.h"

Hero::Hero()
{
    m_Name = "花剑月";
    m_Atk = 50;
    m_Def = 50;
    m_Hp = 500;
    weapon = nullptr;
}

void Hero::equipWeapon(Weapon *wp)
{
    this->weapon = wp;
    cout << "英雄 " << m_Name << " 装备了 " << this->weapon->weaponName << endl;
}

void Hero::Attack(Monster* mt)
{
    int damage = 0;
    int addHp = 0;
    bool isHold = false;
    bool isCrit = false;
    if(this->weapon == nullptr)
    {
        damage = this->m_Atk;
    }
    else
    {
        damage = this->m_Atk + this->weapon->getBaseDamage();
        addHp = this->weapon->suckBlood();
        isHold = this->weapon->freeze();
        isCrit = this->weapon->getCrit();
    }
    if(isCrit)
    {
        damage *= 2;
        cout << "触发暴击,造成 " << damage << " 点伤害";
    }
    if(isHold)
    {
        cout << "触发冰冻，怪物停止攻击一回合" << endl;
    }
    if(addHp>0)
    {
        cout << "触发回血，恢复 " << addHp << " 点血量" << endl;
    }

    mt->m_Hold = isHold;
    int trueDamage = (damage-mt->m_Def>0)?(damage-mt->m_Def):1;
    mt->m_Hp -= trueDamage;
    this->m_Hp += addHp;
    cout << "英雄 " << this->m_Name << " 攻击了 " << mt->m_Name << " ,造成了 " << trueDamage << " 点伤害" << endl;
}
