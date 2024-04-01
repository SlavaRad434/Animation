#pragma once
#include <iostream>
#include<string>
#include<vector>
#include <conio.h>
using namespace std;
bool settingsSize();

struct titles
{
	string name;
	bool fun;
	bool open=1;

};
//titles test = { (string)"Size", (*settingsSize)(), true };
class Menu
{
private:
	vector<titles> _title;

public:
	
	Menu(titles* In, int n);
	void openMenu();

};

Menu::Menu(titles* In,int n) {
	int i;
	for(i=0;i< n;i++)
	_title.push_back(In[i]);
}

void Menu:: openMenu() {
	int i, k;
	char butt;
	vector<titles> bt;
	system("cls");
	for (i = 0, k = 1; i < _title.size(); i++)
		if (_title[i].open) {
			bt.push_back(_title[i]);
			cout << ' ' << k << ')' << _title[i].name << endl;
			k++;}

	butt = (_getch());
	if (butt >= 0x31 && butt <= 0x39)
		bt[(int)(butt - '0')];



};
