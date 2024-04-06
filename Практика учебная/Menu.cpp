#include"Menu.h"



void Menu::drawMenu(vector<titles> bt, int poz) {
	int Menu_i;
	system("cls");
	cout << '\t' << nameMenu << endl;
	for (Menu_i = 0; Menu_i < bt.size(); Menu_i++) {
		cout << ' ' << Menu_i + 1 << ')' << bt[Menu_i].name << '\t' << bt[Menu_i].status << endl;
		//if (bt[Menu_i].status[0] != '\0')

	}
	gotoxy(poz);
	cout << '>';
	gotoxy(bt.size());
}

//void Menu::fn_not_found()
//{
//	cout << "Функция не задана" << endl;
//}

