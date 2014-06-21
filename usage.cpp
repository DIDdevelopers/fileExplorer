#include "menuWidget.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#define DEBUG(x) printf("ERROR: %s \n", x);
using namespace std;
int main()
{

	cMenu *mainWidget = new cMenu;
	string sInput;
	initscr();
	refresh();
	sInput = "Tourist";
	mainWidget->addToMenu(sInput);
	sInput = "Hello";
	mainWidget->addToMenu(sInput);
	sInput = "GoodNight";
	mainWidget->addToMenu(sInput);
	sInput = "Good Afternoon";
	mainWidget->addToMenu(sInput);
	mainWidget->show();
	getch();
	endwin();
}
