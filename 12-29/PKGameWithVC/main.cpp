#include <iostream>
#include <string>
#include "hero.h"
#include "weapon.h""
#include "monster.h"
#include "knife.h"
#include "dargonword.h"
#include <ctime>

using namespace std;

void play()
{
	Hero* hua = new Hero;
	Monster* zz = new Monster;

	Weapon* knife = new Knife;
	Weapon* dargonW = new DargonWord;

	cout << "ÇëÑ¡ÔñÎäÆ÷:" << endl;
	cout << "1.³àÊÖ¿ÕÈ­" << endl;
	cout << "2.Ø°Ê×" << endl;
	cout << "3.ÍÀÁú±¦µ¶" << endl;

	int oper;
	cin >> oper;
	switch (oper) {
	case 1:
		cout << "ÄãÑ¡ÔñÁË " << "1.³àÊÖ¿ÕÈ­" << endl;
		break;
	case 2:
		cout << "ÄãÑ¡ÔñÁË " << "2.Ø°Ê×" << endl;
		hua->equipWeapon(knife);
		break;
	case 3:
		hua->equipWeapon(dargonW);
		cout << "ÄãÑ¡ÔñÁË " << "3.ÍÀÁú±¦µ¶" << endl;
		break;
	}
	getchar();


	int round = 1;
	while (true) {
		getchar();
		system("cls");
		cout << "µÚ" << round << "»ØºÏ" << endl;
		hua->Attack(zz);
		if (zz->m_Hp <= 0)
		{
			cout << "¹ÖÎïËÀÍö£¬ÓÎÏ·Ê¤Àû" << endl;
			break;
		}
		zz->Attack(hua);
		if (hua->m_Hp <= 0)
		{
			cout << "Ó¢ÐÛËÀÍö£¬ÓÎÏ·½áÊø" << endl;
			break;
		}

		cout << "±¾ÂÖ½áÊø" << endl;
		cout << "Ó¢ÐÛÊ£ÓàÑªÁ¿£º" << hua->m_Hp << endl;
		cout << "¹ÖÎïÊ£ÓàÑªÁ¿£º" << zz->m_Hp << endl;
		++round;
	}

	delete hua;
	delete zz;
	delete knife;
	delete dargonW;

}

int main()
{
	srand((unsigned int)time(NULL));
	play();
	return 0;   
}
