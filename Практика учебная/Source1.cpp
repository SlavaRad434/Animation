#pragma once
#include <iostream>
#include<string>
#include<vector>
using namespace std;
bool settingsSize();

struct titles
{
	string name;
	bool fun;
	bool open=1;

};
titles test = { (string)"Size", (*settingsSize)(), true };
class Menu
{
private:
	vector<titles> _title;

public:
	
	Menu(vector<titles> In);
	void openMenu();

};

Menu::Menu(vector<titles> In) {
	_title = In;
}

void Menu:: openMenu() {
	int i, k;

	system("cls");
	for (i = 0, k = 1; i < _title.size(); i++)
		if (_title[i].open)
			cout << ' ' << k << ')' << _title[i].name<<endl;

	switch (_getch())
		case '1':


};