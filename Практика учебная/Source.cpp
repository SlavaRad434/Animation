
#include <Windows.h>
#include <stdio.h>
//#include <time.h>
#include <conio.h>
#include <iostream>
//using namespace std;
#include<string>
#include<vector>
#include <deque>
#include "Graphics.h"
#include "Menu.h"
#include "Shaders.h"

using namespace std;
void settingsSize();


int maxDigit(int x) {
	int i;
	for (i = 1; x = x / 10; i++);
	return i;

}
void maxDigit() {
	int x;
	cout << "������� �����"<< endl;
	cin >> x;
	maxDigit(x);
	cout << x;

}
titles test[] = { { "Size", settingsSize, true,"1280 720"}, {"2", maxDigit, true,"as"}};

Graphics Wid;
Menu M1(test,2);

element el{
	{1.01,0.1},
	{0.01,0.01},
	{0,0,255},

};

//{ (string)"Size", (*settingsSize)(), true }

int main() {
	srand((unsigned int)time(0));
	int i, j, lop = 0, vbeg = 0;;
	int genel;
	vector<Obect> inqueue;
	deque< vector<Obect>> indraw;
	//indraw.push_back()
	//M1.openMenu();
	float disp = 1.0f,spid= -0.2f, begin,end, dt,deb=0;
	Obect invec;
	vector<void*> un1;

	un1.push_back(&disp);
	settingsSize();
	//Graphics Wid;
	COORD A = { Wid.GetWid(),Wid.GetWid() };
	system("cls");
		genel = 5;
		while (genel--) {
			el = {
				{ 1.0f + randf(0.1),randf(2)},
			{0.02,0.02},
			GenRandColor(),
			};
			invec.el = el;
			invec.pShader = Star;
			invec.un = un1;
			inqueue.push_back(invec);
		}
		indraw.push_back(inqueue);
		while (1) {

			begin = clock();
			//if(lop%2)
				system("cls");
			drawObgects(indraw, A, Wid.dc);
			//Star(el, A, Wid.dc, un1);
			end = clock();
			dt = (end - begin) / 1000;
			//cout << deb;
			//deb = indraw[vbeg][0].el.poz.x;
			//cout << deb;
			if (indraw[0][0].el.poz.x < 0.0f) {
				indraw.pop_front();
				//continue;
			}
			for (j = vbeg; j < indraw.size(); j++) {

					for (i = 0; i < indraw[j].size(); i++)
						indraw[j][i].el.poz.x += spid * dt;
			}
			//if (vbeg / 10) {

			//}
			//_getch();
			//Sleep(100);
			if (!(rand() % 5)){
				genel = rand() % 4+1;
				inqueue.clear();
				while (genel--) {

					el = {
				{ 1.0f + randf(0.1),randf(2)},
			{0.02,0.02},
			GenRandColor(),
					};
					invec.el = el;
					invec.pShader = Star;
					invec.un = un1;
					inqueue.push_back(invec);
				}
				
				indraw.push_back(inqueue);
			}
			lop++;
		}
	
	
	//
	//	INPUT_RECORD InRec;
	//	DWORD NumEvents;
	//	ReadConsoleInputW(Wid.dc, &InRec, 1, &NumEvents);
	//	auto old = InRec.Event.WindowBufferSizeEvent.dwSize.X;

	//	
	//for (;;) {
	//	M1.openMenu();

	//	 // M1[1] = test2;
	//	//settingsSize();
	//	//HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//	//COORD A={ 720, 480 };
	//	//Wid.setSizeCon(A);
	//	//ReadConsoleInputW(Wid.dc, &InRec, 1, &NumEvents);
	//	//WaitForSingleObject(Wid.dc, INFINITE);
	//	////Windus.Set_pen(Windus.dc,)
	//	//if(InRec.EventType == WINDOW_BUFFER_SIZE_EVENT)
	//	//Wid.Osi();
	//	//if (InRec.Event.WindowBufferSizeEvent.dwSize.X != old)
	//	//	system("pau");
	//	//old = InRec.Event.WindowBufferSizeEvent.dwSize.X;
	//
	//
	//}
	//

}

int StrToInt(vector<char>s)
{
	int temp = 0; // �����
	int i = 0;
	int sign = 0; // ���� ����� 0- �������������, 1 � �������������
	if (s[0] == '-')
	{
		sign = 1;
		i++;
	}
	while (i<s.size())
	{
		temp = temp + (s[i] & 0x0F);
		temp = temp * 10;
		i++;
	}
	temp = temp / 10;
	if (sign == 1)
		temp = -temp;
	return(temp);
}
// ������� �������������� ����� � ������
char* IntToStr(int n)
{
	char s[40], t, * temp;
	int i, k;
	int sign = 0;
	i = 0;
	k = n;
	if (k < 0)
	{
		sign = 1;
		k = -k;
	}
	do
	{
		t = k % 10;
		k = k / 10;
		s[i] = t | 0x30;
		i++;
	} while (k > 0);
	if (sign == 1)
	{
		s[0] = '-';
		i++;
	}
	temp = new char;
	k = 0;
	i--;
	while (i >= 0)
	{
		temp[k] = s[i];
		i--;
		k++;
	}
	temp[k] = '\0';
	return(temp);
}

void settingsSize() {//int boot;
	//bool flag;
	int i,X=0,Y=0;
	char ch;
	COORD A;
while (1) {	
		system("cls");
		printf_s("����������:\n");
		printf_s("1)320x200\n");
		printf_s("2)640x480\n");
		printf_s("3)1280x720\n");
		printf_s("4)1920x1000\n");
		printf_s("5)������\n");
		printf_s("6)�����\n");



		//scanf_s("%d", &boot);boot
		switch (_getch())
		{
		case '1':
			A = { 320,200 };
			
			break;
		case '2':
			A = { 640,480 };
			
			break;
		case '3':
			A = { 1280,720 };
			
			break;
		case '4':
			A = { 1920,1000 };
			

			break;
		case '5':
			printf_s("������� ���������� ����� ������\n");
			ch = _getch();
			for (i = 0; ch != 27 && ch != '\r' && ch != ' '; i++) {
				if (ch >= 0x30 && ch <= 0x39) {
					X = X + (ch - '0');
					X = X * 10;
					cout << ch;
				}
				ch = _getch();
			}
			X = X / 10;
			if (ch == 27)
				continue;
			else if (ch == '\r')
				cout << endl;
			else 
			cout << ch;
			
			ch = _getch();
			for (i = 0; ch != 27 && ch != '\r' && ch != ' '; i++) {
				if (ch >= 0x30 && ch <= 0x39) {
					Y = Y + (ch - '0');
					Y = Y * 10;
					cout << ch;
				}
				ch = _getch();
			}
			Y = Y / 10;
			if (ch == 27)
				continue;
			else if (ch == '\r')
				cout << endl;
			else
				cout << ch;
			A.Y = Y;
			A.X = X;
			
				//scanf_s("%d%d", (int*)&A.X, (int*)&A.Y);
			
			break;
		case 27:
			
			return ;
			break;
		default:
			continue;
			

		}
		
		Wid.setSizeCon(A);
	}
return ;
}

