#include "menuWidget.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#define DEBUG(x) printf("ERROR: %s \n", x);
using namespace std;
int main()
{

	cMenu *mainWidget = new cMenu;
	initscr();
	cbreak();
	keypad(stdscr, 1);
	noecho();
	refresh();
	string sLine0 = "Tourist";
	mainWidget->addToMenu(sLine0);
	string sLine1 = "Hello";
	mainWidget->addToMenu(sLine1);
	string sLine2 = "GoodNight";
	mainWidget->addToMenu(sLine2);
	string sLine3 = "Good Afternoon";
	mainWidget->addToMenu(sLine3);
	mainWidget->show();
	int nIn = getch();
	while(nIn != 'q')
	{
		mainWidget->onKeyPressed(nIn);
		nIn = getch();
	}
	getch();
	endwin();
}
