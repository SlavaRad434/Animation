#pragma once
#include <Windows.h>
#include <stdio.h>
//#include <time.h>
#include <conio.h>
#include <iostream>
//using namespace std;
#include<string>
#include<vector>
#include<vector>
//#include "Graphics.h"
#include <cmath>
#include <time.h>
#include <deque>
//#include <wingdi.h>

using namespace std;

struct vec2 {
	float x = 0;
	float y = 0;

};
struct vec3 {
	float x ;
	float y ;
	float z ;

};
struct COLOR 
{
	unsigned char R;
	unsigned char G;
	unsigned char B;

};

COLOR operator* (COLOR cord, float k);




//typedef void Shader;
typedef void Shader;



struct element
{
	vec2 poz;
	vec2 size;
	COLOR color;
	
};

struct realPoz 
{
	COORD A;
	COORD B;
};
struct Obect
{
	element el;
	vector<void*> un;
	Shader(*pShader)(element, COORD, HDC, vector<void*>);
};

//Shader(*pShader)(element);

//typedef	vector<element> Obect;
//Shader(*pSh)(element);

Shader Star(element el, COORD winsiz, HDC dc, vector<void*> vunif);

//Shader (*pShader)(element);
//void drawelement(element el);
void drawObgects(vector<Obect>, COORD winsiz, HDC dc);

Shader Recurs(element el, COORD winsiz, HDC dc, vector<void*> vunif);

Shader treugolnic(element el, COORD winsiz, HDC dc, vector<void*> vunif);

Shader ShDvig(element el, COORD winsiz, HDC dc, vector<void*> vunif);

void converting(element el, COORD winsiz, realPoz* BufPoz);


COLOR GenRandColor();

float randf(float max);
