#pragma once
#include <iostream>
#include<string>
#include<vector>
#include <conio.h>
using namespace std;


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
		int Menu_i, Menu_k;
		char butt;
		vector<titles> bt;
		system("cls");
		for (Menu_i = 0, Menu_k = 1; Menu_i < _title.size(); Menu_i++)
			if (_title[Menu_i].open) {
				bt.push_back(_title[Menu_i]);
				cout << ' ' << Menu_k << ')' << _title[Menu_i].name << endl;
				Menu_k++;
			}

		butt = (_getch());
		if (butt >= 0x31 && butt <= 0x39)
			bt[(int)(butt - '1')].fn;



	}
};
