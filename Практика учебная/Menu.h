#pragma once
#include <iostream>
#include<string>
#include<vector>
#include <conio.h>
#include <Windows.h>
using namespace std;

//void gotoxy(short x);
struct titles
{
	string name;
	void (*fn)();
	bool open=1;

};
//titles test = { (string)"Size", (*settingsSize)(), true };
class Menu
{
private:
	vector<titles> _title;

public:

	//Menu(titles* In, int n);
	//void openMenu();

	Menu(titles* In, int n) {
		int Menu_i;
		for (Menu_i = 0; Menu_i < n; Menu_i++)
			_title.push_back(In[Menu_i]);
	}

	void openMenu() {
		int Menu_i, Menu_k, poz = 0;
		COORD pozCursor;
		char butt;
		vector<titles> bt;
		for (Menu_i = 0, Menu_k = 1; Menu_i < _title.size(); Menu_i++)
			if (_title[Menu_i].open) {
				bt.push_back(_title[Menu_i]);
			}
		while (1)
		{
			system("cls");
			for(Menu_i = 0, Menu_k = 1; Menu_i < bt.size(); Menu_i++)
					cout << ' ' << Menu_i+1 << ')' << bt[Menu_i].name << endl;
				
					
				
			gotoxy(poz);
					cout << '>';
					gotoxy(bt.size());

			butt = (_getch());
			if (butt >= 0x31 && butt <= 0x39)
				bt[(int)(butt - '1')].fn();
			else if (butt == 72) {

				gotoxy(poz);
				cout << ' ';
				if (poz)
					poz--;
				else
					poz = bt.size();
				gotoxy(poz);
				cout << '>';
			}
			else if (butt == 80) {

				gotoxy(poz);
				cout << ' ';
				if (poz < bt.size()-1)
					poz++;
				else
					poz = 0;
				gotoxy(poz);
				cout << '>';
			}
			else if (butt == 72) {

				gotoxy(poz);
				cout << ' ';
				if (poz)
					poz++;
				else
					poz = bt.size() - 1;
				gotoxy(poz);
				cout << '>';
			}
			else if (butt == '\r')
				bt[poz].fn();

		}
	
	}
void gotoxy(short x)
{
	COORD Coor;
	Coor.X = 0; Coor.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
}
	titles operator[](int i) { return _title[i-1]; }
	//void rename (string newName) {}
};

