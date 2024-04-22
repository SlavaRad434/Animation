#pragma once
//Директива  #pragma once  указывает препроцессору,
//что файл подключается только один раз.
#include <windows.h>
#include <stdio.h>
//#include <time.h>
#include <conio.h>
#include <iostream>
//using namespace std;
#include<string>
#include<vector>


//struct vec2 {
//	float x = 0;
//	float y = 0;
//
//};
//struct vec3 {
//	float x;
//	float y;
//	float z;
//
//};
//
//typedef void Shader;
//
//struct element
//{
//	vec2 poz;
//	vec2 size;
//	COLORREF color;
//	Shader* shader;
//};
//typedef	vector<element> Obect;
//Shader(*pShader)(element);
//
////Shader Star(element el);
//Shader(*pShader)(element);
class Graphics
{
private:
	HPEN hPen = NULL;
	HBRUSH hBrush = NULL;
	HWND hWnd = NULL;
	int wid, heg;


public:
	HDC dc,dc1;
	void Set_pen(HDC dc, COLORREF, int);
	void Set_brush(HDC dc, COLORREF, bool);
	void Line(HDC dc, int, int, int, int);
	void Point(HDC dc, int, int, COLORREF);
	void Osi(  );
	int GetWid() { return wid; }
	int GetHeg() { return heg; }
	void setSizeCon(COORD A);
	Graphics();
	~Graphics();
};

Graphics::Graphics()
{
	hWnd = GetConsoleWindow();
	dc = GetDC(hWnd);
	RECT rect;
	GetClientRect(hWnd, &rect);
	wid = rect.right;
	heg = rect.bottom;
	Set_pen(dc, RGB(255, 255, 255), 1);
	Set_brush(dc, RGB(255, 255, 255), true);
}

Graphics::~Graphics()
{
	DeleteObject(hPen);
	DeleteObject(hBrush);
	ReleaseDC(hWnd, dc);
	DeleteDC(dc);
}
void Graphics::Set_pen(HDC dc, COLORREF col, int w)
{
	DeleteObject(hPen);
	hPen = CreatePen(PS_INSIDEFRAME, w, col);
	SelectObject(dc, hPen);
}
void Graphics::Set_brush(HDC dc, COLORREF col, bool empty)
{
	DeleteObject(hBrush);
	empty ? hBrush = ::CreateSolidBrush(col) : 
			hBrush = ::CreateSolidBrush(NULL_BRUSH);
	::SelectObject(dc, hBrush);
}
void Graphics::Line(HDC dc, int x1, int y1, int x2, int y2)
{
	MoveToEx(dc, x1, y1, NULL);
	LineTo(dc, x2, y2);
}
void Graphics::Point(HDC dc, int x, int y, COLORREF col)
{
	SetPixel(dc, x, y, col);
}
void Graphics::Osi()
{
	Set_pen(dc, RGB(255, 0, 0), 2);
	Line(dc, 0, heg / 2, wid - 1, heg / 2);
	Set_pen(dc, RGB(0, 255, 0), 2);
	Line(dc, wid / 2, 0, wid / 2, heg - 1);
}
void Graphics::setSizeCon(COORD A) {
	CONSOLE_FONT_INFO  Font;
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//out_handle = GetStdHandle(GENERIC_READ);
	if (!GetCurrentConsoleFont(out_handle, 1, &Font)) {
		auto err = GetLastError();
		std::cout << err;
		system("pause");
	}
	COORD  CharSiz{
		8, 12
	};
	CharSiz = GetConsoleFontSize(out_handle, Font.nFont);

	 //out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	 
	COORD crd = { A.X / CharSiz.X-4, A.Y / CharSiz.Y-4 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	MoveWindow(hWnd, 0, 0, CharSiz.X, CharSiz.Y, 1);
	if (!SetConsoleScreenBufferSize(out_handle, crd)) {
		//auto err = GetLastError();
		//std::cout << err;

		//system("pause");
	}
	MoveWindow(hWnd,0,0,A.X,A.Y,1);
	//SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
	wid = A.X;
		heg = A.Y;
}

//RECT scr;
//GetWindowRect(hWnd, &scr);
//int xpos = GetSystemMetrics(SM_CXSCREEN/2 - (scr.right-scr.left)/2);
//int ypos = GetSystemMetrics(SM_CYSCREEN/2 - (scr.bottom-scr.top)/2);
//SetWindowPos(hWnd, HWND_TOP, xpos, ypos, 0, 0, SWP_NOSIZE); 

//int setSizeCon(COORD A) {
//
//	COORD  CharSiz{ 8,12 };
//	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	COORD crd = { A.X / CharSiz.X, A.Y / CharSiz.Y };
//	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
//	SetConsoleScreenBufferSize(out_handle, crd);
//	MoveWindow();
//	//SetConsoleWindowInfo(out_handle, true, &src);
//	SetConsoleScreenBufferSize(out_handle, crd);
//	
//	return 1;
//}