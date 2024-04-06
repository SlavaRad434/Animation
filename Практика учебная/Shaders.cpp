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

	for (j = BufPoz.A.Y, elPoz.y = -1; j < BufPoz.B.Y&& j < winsiz.Y; j++, elPoz.y += fabs(2 / elSize.y))
		for (i = BufPoz.A.X, elPoz.x=-1; i < BufPoz.B.X && j < winsiz.Y; i++, elPoz.x += fabs(2 / elSize.x)) {
			if ((pow(elPoz.x,2) + pow(elPoz.y,2)) <= 1) {
				ColBuf = (el.color * (1 - dicp * (pow(elPoz.x, 2) + pow(elPoz.y, 2))));
				col = RGB(ColBuf.R, ColBuf.G, ColBuf.B);
				SetPixel(dc, i, j, col);
			}

				}
};



COLOR operator* (COLOR cord, float k) {
	cord.B *= k;
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
	return rand() % 100000 / 100000.0 * max;

}
void drawObgects(vector<Obect> obect, COORD winsiz, HDC dc) {
	int i;
	for (i = 0; i < obect.size(); i++)
		obect[i].pShader(obect[i].el, winsiz, dc, obect[i].un);


}

#undef i 
#undef j