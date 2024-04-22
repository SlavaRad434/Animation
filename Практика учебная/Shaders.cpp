#include "Shaders.h"
//realPoz BufPoz;

#define i Shader_i
#define j Shader_j

void converting(element el, COORD winsiz, realPoz* BufPoz) {
	
	(*BufPoz).A.X = (int)((el.poz.x - el.size.x / 2)  * winsiz.X);
	(*BufPoz).A.Y = (int)((el.poz.y - el.size.y / 2) * winsiz.Y);
	(*BufPoz).B.X = (int)((el.poz.x + el.size.x / 2) * winsiz.X);
	(*BufPoz).B.Y = (int)((el.poz.y + el.size.y / 2) * winsiz.Y);
	return;

}
//void checkPer (realPoz* BufPoz,)

Shader Star(element el, COORD winsiz, HDC dc, vector<void*> vunif) {
	el.size.y *= (float)winsiz.X/(float)winsiz.Y;
	realPoz BufPoz;
int Shader_i, Shader_j;	
	float rad;
	const float dicp = *(float*)vunif[0];
	converting (el, winsiz, &BufPoz);
	vec2 elPoz = {-1,-1};
	vec2 elSize = { BufPoz.A.X - BufPoz.B.X,BufPoz.A.Y - BufPoz.B.Y };
	//SetPixel(dc, x, y, el.c);
	COLOR ColBuf;
	COLORREF col;
	rad = (el.size.x) / 2;
 // if(BufPoz)
	//if((BufPoz.B.X - BufPoz.A.X)>(BufPoz.B.Y - BufPoz.A.Y)){
	//	BufPoz.A.X = (BufPoz.B.X - BufPoz.A.X) / 2 - (BufPoz.B.Y - BufPoz.A.Y) / 2;
	//	BufPoz.B.X = (BufPoz.B.X - BufPoz.A.X) / 2 + (BufPoz.B.Y - BufPoz.A.Y) / 2;
	//	}
	//else {
	//	BufPoz.A.Y = (BufPoz.B.Y - BufPoz.A.Y) / 2 - (BufPoz.B.X - BufPoz.A.X) / 2;
	//	BufPoz.B.Y = (BufPoz.B.Y - BufPoz.A.Y) / 2 + (BufPoz.B.X - BufPoz.A.X) / 2;
	//}
	if(winsiz.X > winsiz.Y)

		
	for (j = BufPoz.A.Y, elPoz.y = -1; j < BufPoz.B.Y&& j < winsiz.Y; j++, elPoz.y += fabs(2 / elSize.y))
		for (i = BufPoz.A.X, elPoz.x=-1; i < BufPoz.B.X && j < winsiz.Y; i++, elPoz.x += fabs(2 / elSize.x)) {

			if ((pow(elPoz.x,2) + pow(elPoz.y,2)) <= 1) {
				ColBuf = (el.color * (1 - dicp * (sqrt(abs(elPoz.x)) * sqrt(abs(elPoz.y)))));
				col = RGB(ColBuf.R, ColBuf.G, ColBuf.B);
				SetPixel(dc, i, j, col);
			}

				}
};
COORD bufBegin;
void recLin(HDC dc, realPoz BufPoz,COORD beg, int depth,COLORREF col,float XonY,int ed) {
	if (depth) {
		if (beg.Y >= BufPoz.A.Y && beg.Y <= BufPoz.B.Y, beg.X >= BufPoz.A.X, beg.X <= BufPoz.B.X) {

			//(dc, beg.X, beg.Y, col);
			MoveToEx(dc, beg.X, beg.Y, NULL);
			//LineTo(dc, beg.X - (BufPoz.B.X- BufPoz.A.X)/ed, (beg.X - (BufPoz.B.X - BufPoz.A.X) / ed)/XonY);
			//beg.X -= 1;
			//beg.Y -= 1;
			//if (BufPoz.A.Y <= (beg.X - (BufPoz.B.X - BufPoz.A.X) / ed) / XonY) 
			{
				MoveToEx(dc, beg.X, beg.Y, NULL);
				LineTo(dc, beg.X - (BufPoz.B.X - BufPoz.A.X) / ed, (beg.Y + (BufPoz.B.Y - BufPoz.A.Y) / (ed*2)));
				bufBegin.X = beg.X - (BufPoz.B.X - BufPoz.A.X) / ed;
				bufBegin.Y = (beg.Y + (BufPoz.B.Y - BufPoz.A.Y) / (ed * 2));
					recLin(dc, BufPoz, bufBegin, depth - 1, col, XonY, ed);
			}
			//beg.Y += 2;
			//if (BufPoz.B.Y >= (beg.X - (BufPoz.B.X - BufPoz.A.X) / ed) / XonY)
			{
				MoveToEx(dc, beg.X, beg.Y, NULL);
				LineTo(dc, beg.X - (BufPoz.B.X - BufPoz.A.X) / ed, (beg.Y - (BufPoz.B.Y - BufPoz.A.Y) / (ed*2)));
				bufBegin.X = beg.X - (BufPoz.B.X - BufPoz.A.X) / ed;
				bufBegin.Y = (beg.Y - (BufPoz.B.Y - BufPoz.A.Y) / (ed * 2));
				recLin(dc, BufPoz, bufBegin, depth - 1, col, XonY, ed);
			}

			//recLin(dc, BufPoz, beg, depth - 1, col, XonY, ed);
		}
	}


	/*if (depth) {
		COORD beg, end;
		if (depth % 2) {
			beg.X = (short)BufPoz.A.X / 2;
			beg.Y = (short)BufPoz.A.Y;
			end.X = (short)BufPoz.B.X / 2;
			end.Y = (short)BufPoz.B.Y;
		}
		else{
			beg.X = (short)BufPoz.A.X ;
		    beg.Y = (short)BufPoz.A.Y/ 2;
		    end.X = (short)BufPoz.B.X ;
		    end.Y = (short)BufPoz.B.Y/ 2;
		}
		MoveToEx(dc, beg.X, beg.Y, NULL);
		LineTo(dc, end.X, end.Y);
		recLin()
	}*/
}

Shader Recurs(element el, COORD winsiz, HDC dc, vector<void*> vunif) {
	realPoz BufPoz;
	

	el.size.y = el.size.y * el.size.x* (winsiz.X / (float)winsiz.Y);//выравнивание соотношения сторон назависимо от формата окна
	int Shader_i, Shader_j;// таймеры
	converting(el, winsiz, &BufPoz);//перевод из относительных корденет в реальне
	//юниформы
	int depth = *(int*)vunif[0];
	COLORREF col = *(COLORREF*)vunif[2];
	float fwidth = *(float*)vunif[1];
	int de = *(int*)vunif[3];
	int width = (BufPoz.B.Y- BufPoz.A.Y)/100.0* fwidth;
	COORD beg;
		beg.Y= BufPoz.A.Y+((BufPoz.B.Y - BufPoz.A.Y)/2);
		beg.X = BufPoz.B.X- width-2;

	//vec2 elSize = { BufPoz.A.X - BufPoz.B.X,BufPoz.A.Y - BufPoz.B.Y };
	//Set_brush();
	//auto hPen = CreatePen(PS_INSIDEFRAME, 10, RGB(el.color.R, el.color.G, el.color.B));
		//задний фон
	auto hBrush = CreateSolidBrush(RGB(el.color.R, el.color.G, el.color.B));
	SelectObject(dc, hBrush);
	auto hPen = CreatePen(PS_INSIDEFRAME, 1, RGB(el.color.R, el.color.G, el.color.B));
	SelectObject(dc, hPen);
	Rectangle(dc,BufPoz.A.X, BufPoz.A.Y, BufPoz.B.X, BufPoz.B.Y);
	DeleteObject(hBrush);
	DeleteObject(hPen);



	 hPen = CreatePen(PS_INSIDEFRAME, width, col);
	SelectObject(dc, hPen);
		recLin(dc, BufPoz, beg, depth, col, (winsiz.X / (float)winsiz.Y), de);
		DeleteObject(hPen);
};

Shader treugolnic(element el, COORD winsiz, HDC dc, vector<void*> vunif) {
	realPoz BufPoz;
	converting(el, winsiz, &BufPoz);
	POINT treugol[3]{
		{BufPoz.A.X,BufPoz.A.Y},{BufPoz.A.X,BufPoz.B.Y},{BufPoz.B.X,BufPoz.A.Y+(BufPoz.B.Y - BufPoz.A.Y) / 2}
	};
	auto hBrush = CreateSolidBrush(RGB(el.color.R, el.color.G, el.color.B));
	SelectObject(dc, hBrush);
	auto hPen = CreatePen(PS_INSIDEFRAME, 1, RGB(el.color.R, el.color.G, el.color.B));
	SelectObject(dc, hPen);
	Polygon(dc, treugol, 3);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}


COLOR operator* (COLOR cord, float k) {
	cord.R *= k;
	cord.G *= k;
	cord.B *= k;
	return cord;
};

COLOR GenRandColor() {
	COLOR A;
	A.B = rand() % 256;
	A.R = rand() % 256;
	A.G = rand() % 256;
	return A;
}
float randf(float max) {
	return (rand() % 10000) / 10000.0 * max;

}
void drawObgects(vector<Obect> obect, COORD winsiz, HDC dc) {
	int i,j;
	for (j = 0; j < obect.size(); j++)
		obect[j].pShader(obect[j].el, winsiz, dc, obect[j].un);

}

#undef i 
#undef j