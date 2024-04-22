
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
	cout << "Введите число"<< endl;
	cin >> x;
	maxDigit(x);
	cout << x;

}
titles test[] = { { "Size", settingsSize, true,"1280 720"}, {"2", maxDigit, true,"as"}};

Graphics Wid;//окно
Menu M1(test,2);//меню
vector<Obect> rocet;
//element corpys,obtec,dvig;

element corpys  {
	{0.5f,0.5f},
	{0.15f, 0.35f},
	{0,0,255},
};

element optec{
	{ 0.5f,0.49999f},
	{ 0.15f /3, 0.10f},
	{255,255,255},

};



element el{
	{1.01,0.1},
	{0.01,0.01},
	{0,0,255},
};

//{ (string)"Size", (*settingsSize)(), true }

int main() {
	HDC dc2;
	srand((unsigned int)time(0));
	int i, j, lop = 0, vbeg = 0;//счетчики

	int genSta=5, maxColvoBildStar=4;//1/n шанс создать новый массив звезд
	//максимальное -1 количество звезд которое может создаться 
	
	int genel;
	//vector<Obect> rocet;
	vector<Obect> indraw,indrawRocet;//группа обьектов
	deque< vector<Obect>> deqStar;//двустороний вектор для удаления первого элемента
	//indraw.push_back()
	//M1.openMenu();
	
	float disp = 1.0f, spidStar = -0.1f, begin, end, dt, deb = 0, spidRec = 3;
	//Изменение цвета
	//Скорость звезд в экранах в секунду
	//время начала
	//время конца
	//изменение времени
	//
	Obect invec;
	vector<void*> un1,uncorp;

	settingsSize();
	//auto dc1 = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, 0, CONSOLE_TEXTMODE_BUFFER, 0);
	//SetConsoleActiveScreenBuffer(dc1);

	//Юниформ переменная для звезды
	un1.push_back(&disp);
	
	//Graphics Wid;
	COORD A = { Wid.GetWid(),Wid.GetHeg() };

	//Юниформ переменные для Корпус
	int corpdepth = 0;
	float fcorpdepth = 0;
	uncorp.push_back((void*)&corpdepth);//[0]
	
	float widthpen = 3;
	uncorp.push_back((void*)&widthpen);//[1]

	COLORREF corpRecCol= RGB(255, 0, 0);
	uncorp.push_back((void*)&corpRecCol);//[2]
	int de = 5;
	uncorp.push_back((void*)&de);//[3]


	//
		//genel = 5;
		invec.el = corpys;
		invec.pShader = Recurs;
		invec.un = uncorp;
		indrawRocet.push_back(invec);

		invec.el = optec;
		invec.pShader = treugolnic;
		invec.un = uncorp;
		indrawRocet.push_back(invec);
		//while (genel--) {
		//	el = {
		//		{ 1.0f + randf(0.1),randf(1)},
		//	{0.01,0.01},
		//	GenRandColor(),
		//	};
		//	invec.el = el;
		//	invec.pShader = Star;
		//	invec.un = un1;
		//	indraw.push_back(invec);
		//}

		//deqStar.push_back(indraw);
		system("cls");

		dc2 = CreateCompatibleDC(Wid.dc);//Создание совместимого контескста
	auto bitMap = CreateCompatibleBitmap(Wid.dc,Wid.GetWid(), Wid.GetHeg());//создание растрового изображения
	SelectObject(dc2, bitMap);//выбор изображения для рисования
	begin = clock();

	//bitMap = CreateCompatibleBitmap(Wid.dc, Wid.GetWid(), Wid.GetHeg());
		while (1) {
			//SetConsoleActiveScreenBuffer(dc1);

			//drawObgects(indrawRocet, A, dc2);//нарисовать ракету

			begin = clock();

			if (BitBlt(Wid.dc, 0, 0, Wid.GetWid(), Wid.GetHeg(), dc2, 0, 0, SRCCOPY))//прямое копирование пикселей в окно
				DeleteObject(bitMap);//
			bitMap = CreateCompatibleBitmap(Wid.dc, Wid.GetWid(), Wid.GetHeg());
			SelectObject(dc2, bitMap);
			//if(!SwapBuffers(dc2))
			//	cout<<GetLastError();
				
				//drawObgects(indrawRocet, A, dc2);
				for(i=0;i< deqStar.size();i++)
			drawObgects(deqStar[i], A, dc2);
				drawObgects(indrawRocet, A, dc2);
				
			//Star(el, A, dc2, un1);
			end = clock();
			dt = (end - begin) / 1000;
			//cout << 1/dt;
			//deb = indraw[vbeg][0].el.poz.x;
			//cout << deb;
			if (deqStar.size()) {
				if (deqStar[0][0].el.poz.x < 0.0f) {
					deqStar.pop_front();
				}
				for (j = vbeg; j < deqStar.size(); j++) {

					for (i = 0; i < deqStar[j].size(); i++)
						deqStar[j][i].el.poz.x += spidStar * dt;
				}
			}
			//if (vbeg / 10) {

			//}
			//_getch();
			//Sleep(100);
			if (!(rand() % 5)){
				genel = rand() % maxColvoBildStar + 1;
				indraw.clear();
				while (genel--) {

					el = {
				{ 1.0f + randf(0.1),randf(1)},
			{0.01,0.01},
			GenRandColor(),
					};
					invec.el = el;
					invec.pShader = Star;
					invec.un = un1;
					indraw.push_back(invec);
				}
			//	SetConsoleActiveScreenBuffer(dc2);
				deqStar.push_back(indraw);
			}
			lop++;

			fcorpdepth += dt * spidRec;
			corpdepth = fcorpdepth;
			corpdepth %= de;
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
	int temp = 0; // число
	int i = 0;
	int sign = 0; // знак числа 0- положительное, 1 — отрицательное
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
// Функция преобразования числа в строку
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
		printf_s("Резрешения:\n");
		printf_s("1)320x200\n");
		printf_s("2)640x480\n");
		printf_s("3)1280x720\n");
		printf_s("4)1920x1000\n");
		printf_s("5)Другое\n");
		printf_s("6)Назад\n");



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
			X = 0;
			Y = 0;
			printf_s("Введите разрешение через пробел\n");
			ch = _getch();
			for (i = 0; ch != 27 && ch != '\r' && ch != ' '; i++) {
				if (ch >= 0x30 && ch <= 0x39) {
					X = X + (ch - '0');
					X = X * 10;
					cout << ch;
				}
				ch = _getch();
			}
			X = (X / 10);
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
			Y = (Y / 10);
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

