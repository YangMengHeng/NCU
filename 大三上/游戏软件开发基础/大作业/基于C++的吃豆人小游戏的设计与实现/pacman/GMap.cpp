#include "stdafx.h"
#include "GMap.h"

int GMap::LD = 36;
int GMap::PD = 3;

void GMap::InitOP()
{
	peaMapData[E_ROW][E_ARRAY] = false;
	peaMapData[P_ROW][P_ARRAY] = false;
}
void GMap::DrawMap(HDC &memDC)
{
	HBRUSH hBrush = CreateSolidBrush(color);
	for (int i = 0; i < MAPLENTH; i++) {
		for (int j = 0; j < MAPLENTH; j++) {
			
			if (!mapData[i][j]) {
				RECT rect;
				rect.left = j * LD;
				rect.top = i * LD;
				rect.right = (j + 1) * LD;
				rect.bottom = (i + 1) * LD;
				FillRect(memDC, &rect, hBrush);
			}
		}
	}
	DeleteObject(hBrush);
}
void GMap::DrawPeas(HDC &hdc)
{
	for (int i = 0; i < MAPLENTH; i++) {
		for (int j = 0; j < MAPLENTH; j++) {
			if (peaMapData[i][j]) {
			
				Ellipse(hdc, (LD / 2 - PD) + j * LD, (LD / 2 - PD) + i * LD, (LD / 2 + PD) + j * LD, (LD / 2 + PD) + i * LD);
			}
		}
	}


	
		
}
GMap::~GMap()
{

}

#define A true 
#define B false 
bool Stage_1::initData[MAPLENTH][MAPLENTH] = {
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B, 
	B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, 
	B, A, A, B, A, A, B, B, B, A, B, B, B, A, A, B, A, A, B, 
	B, A, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, A, B, 
	B, A, B, A, A, A, B, B, B, A, B, B, B, A, A, A, B, A, B, 
	B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B, 
	B, A, A, A, A, A, B, B, A, A, A, B, B, A, A, A, A, A, B, 
	B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B, 
	B, A, B, A, A, A, A, A, B, A, B, A, A, A, A, A, B, A, B, 
	A, A, A, A, A, A, A, A, B, B, B, A, A, A, A, A, A, A, A, 
	B, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, B, A, B, 
	B, A, B, A, A, B, A, A, A, A, A, A, A, B, A, A, B, A, B, 
	B, A, B, A, B, B, B, A, A, A, A, A, B, B, B, A, B, A, B, 
	B, A, A, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, 
	B, A, B, B, A, A, A, A, A, A, A, A, A, A, A, B, B, A, B, 
	B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, 
	B, A, A, A, A, B, B, B, A, B, A, B, B, B, A, A, A, A, B, 
	B, A, A, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, 
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B, 
};
#undef A
#undef B
Stage_1::Stage_1()
{
	color = RGB(0, 0, 0);
	for (int i = 0; i < MAPLENTH; i++) {
		for (int j = 0; j < MAPLENTH; j++) {
			this->mapData[i][j] = this->initData[i][j];
			this->peaMapData[i][j] = this->initData[i][j];
		}
	}

	this->InitOP();
}

#define A true
#define B false
bool Stage_2::initData[MAPLENTH][MAPLENTH] = {
	B, B, B, B, B, B, B, B, B, A, B, B, B, A, B, B, B, B, B, 
	A, A, A, A, A, A, A, B, A, A, B, A, A, A, B, A, B, A, A, 
	B, A, A, A, B, A, A, B, A, A, B, A, B, A, B, A, B, A, B, 
	B, B, B, A, B, A, A, B, B, A, B, A, B, A, B, A, B, B, B, 
	B, A, A, A, A, A, A, A, A, A, A, A, B, B, B, A, A, A, B, 
	B, A, A, B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, 
	B, A, A, B, A, A, A, B, B, B, B, B, B, A, A, B, A, A, B, 
	B, A, A, B, A, B, A, A, A, A, A, A, A, A, A, B, A, A, B, 
	B, A, A, B, A, B, A, A, B, A, B, A, A, B, A, B, A, A, B, 
	A, A, A, B, A, B, A, A, B, B, B, A, A, B, A, B, A, A, A, 
	B, A, A, B, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, 
	B, A, A, B, A, A, A, B, B, B, B, B, A, B, A, A, A, A, B, 
	B, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, B, 
	B, A, A, A, B, B, B, B, B, B, B, A, A, A, A, A, A, A, B, 
	B, A, A, A, A, A, A, A, A, A, A, A, A, B, A, A, A, A, B, 
	B, B, B, B, B, A, A, A, A, B, B, B, A, B, A, A, A, A, B, 
	B, A, A, A, B, B, B, A, A, A, A, B, A, B, B, B, A, A, B, 
	A, A, A, A, B, A, A, A, A, A, A, B, A, A, A, B, A, A, A, 
	B, B, B, B, B, B, B, B, B, A, B, B, B, A, B, B, B, B, B, 
};
#undef A
#undef B
Stage_2::Stage_2()
{
	color = RGB(0, 0, 0);
	for (int i = 0; i < MAPLENTH; i++) {
		for (int j = 0; j < MAPLENTH; j++) {
			this->mapData[i][j] = this->initData[i][j];
			this->peaMapData[i][j] = this->initData[i][j];
		}
	}

	this->InitOP();
}

#define A true
#define B false
bool Stage_3::initData[MAPLENTH][MAPLENTH] = {
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B, 
	A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, A, 
	B, A, A, B, A, A, B, B, B, B, B, B, B, A, A, A, B, A, B, 
	B, A, B, B, A, A, A, A, A, A, A, A, B, A, A, A, B, A, B, 
	B, A, B, A, A, A, B, B, B, B, B, B, B, A, A, A, B, A, B, 
	B, A, B, A, B, B, B, A, A, A, A, A, B, B, B, A, B, A, B, 
	B, A, A, A, B, A, B, A, A, A, A, A, A, A, A, A, B, A, B, 
	B, A, B, A, B, A, A, A, A, A, A, A, A, B, A, A, B, A, B, 
	B, A, B, A, B, B, A, A, B, A, B, A, A, B, A, A, B, A, B, 
	B, A, A, A, A, B, A, A, B, B, B, A, A, B, A, A, B, A, B, 
	B, A, B, A, A, B, A, A, A, A, A, A, A, B, A, A, A, A, B, 
	B, A, B, A, A, B, A, A, A, A, A, A, B, B, B, A, B, A, B, 
	B, A, B, A, A, B, A, B, B, B, B, B, B, A, B, A, B, A, B, 
	B, A, B, A, A, B, A, A, A, A, A, A, A, A, B, A, B, A, B, 
	B, A, B, B, A, B, B, B, B, B, B, A, B, A, B, A, B, A, B, 
	B, A, A, A, A, B, A, A, A, A, A, A, B, A, B, A, B, A, B, 
	B, B, B, B, B, B, A, A, B, B, B, A, B, A, B, A, B, A, B, 
	A, A, A, A, A, A, A, A, B, A, A, A, A, A, B, A, A, A, A, 
	B, B, B, B, B, B, B, B, B, A, B, B, B, B, B, B, B, B, B,
};
#undef A
#undef B
Stage_3::Stage_3()
{
	color = RGB(0, 0, 0);
	for (int i = 0; i < MAPLENTH; i++) {
		for (int j = 0; j < MAPLENTH; j++) {
			this->mapData[i][j] = this->initData[i][j];
			this->peaMapData[i][j] = this->initData[i][j];
		}
	}

	this->InitOP();
}