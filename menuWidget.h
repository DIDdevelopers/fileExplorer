#ifndef WID_H
#define WID_H
#include "wid.h"
#endif
#include <string>
#include <iostream>
#include <menu.h>
#include <stdlib.h>
using namespace std;
#define MENU_MAX 10

class cMenu:protected cWidget
{
public:
	cMenu():cWidget(LINES, COLS, 0, 0)
	{
		m_nSelected = 0;
		m_Items = (ITEM **)calloc( 10, sizeof(ITEM *));
		printf("Base arry %p\n", m_Items);
		m_Items[0] = NULL;
		printf("%p\n", m_Items);
		printf("%p\n", m_Items[0]);
		getch();
		
	}
	cMenu(int nHeight, int nWidth, int nX, int nY):cWidget(nHeight, nWidth, nX, nY)
	{
		m_nSelected = 0;
		m_Items = (ITEM **)calloc( 10, sizeof(ITEM *));
		m_Items[0] = NULL;
	}
	void show();
	void addToMenu(std::string sItem);
	bool onKeyPressed(int nKey);
	bool onSelected(int nSelected);

private:
	int m_nSelected;
	ITEM **m_Items;
	MENU *m_Menu;
};
