#pragma once
#include <iostream>
#include<string>
#include<vector>
#include <conio.h>
#include <Windows.h>
using namespace std;

//void gotoxy(short x);
//template <class T>
struct titles
{
	string name;
    void (*fn)();
	bool open=1;
	string status = "\0";

};
//titles test = { (string)"Size", (*settingsSize)(), true };
class Menu
{
private:
	//string nameMenu = '\0';
	vector<titles> _title;


	void drawMenu(vector<titles> bt, int poz);
	//{
	//	int Menu_i;
	//	system("cls");
	//	cout << '\t' << nameMenu << endl;
	//	for (Menu_i = 0; Menu_i < bt.size(); Menu_i++) {
	//		cout << ' ' << Menu_i + 1 << ')' << bt[Menu_i].name << '\t' << bt[Menu_i].status << endl;
	//		//if (bt[Menu_i].status[0] != '\0')

	//	}
	//	gotoxy(poz);
	//	cout << '>';
	//	gotoxy(bt.size());
	//}

	void fn_not_found()
	{
		cout << "������� �� ������" << endl;
	}
	

public:
	string nameMenu = "\0";
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
		
           drawMenu(bt,poz);
		while (1)
		{
			
			//system("cls");
			//for (Menu_i = 0, Menu_k = 1; Menu_i < bt.size(); Menu_i++) {
			//	cout << ' ' << Menu_i + 1 << ')' << bt[Menu_i].name <<'\t'<< bt[Menu_i].status << endl;
			//	//if (bt[Menu_i].status[0] != '\0')
			//}
			//		
			//	
			//gotoxy(poz);
			//		cout << '>';
			//		gotoxy(bt.size());

			butt = (_getch());

			if (butt >= 0x31 && butt <= 0x39) {
				if ((int)(butt - '1') < bt.size())
					bt[(int)(butt - '1')].fn();
				drawMenu(bt, poz);
			}
			else if (butt == 72) {

				gotoxy(poz);
				cout << ' ';
				if (poz)
					poz--;
				else
					poz = bt.size() - 1;
				gotoxy(poz);
				cout << '>';
				gotoxy(bt.size());
			}
			else if (butt == 80) {

				gotoxy(poz);
				cout << ' ';
				if (poz < bt.size() - 1)
					poz++;
				else
					poz = 0;
				gotoxy(poz);
				cout << '>';
				gotoxy(bt.size());
			}
			//else if (butt == 72) {

			//	gotoxy(poz);
			//	cout << ' ';
			//	if (poz)
			//		poz++;
			//	else
			//		poz = bt.size() - 1;
			//	gotoxy(poz);
			//	cout << '>';
			//}
			else if (butt == '\r') {
				bt[poz].fn();
				drawMenu(bt, poz);
			}
			else if (butt == '\r');

			else if (butt == 8)
				return;
		}
	
	}
void gotoxy(short x)
{
	COORD Coor;
	Coor.X = 0; Coor.Y = x+1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
}
	titles operator[](int i) { return _title[i-1]; }
};

