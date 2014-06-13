#include "menu.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#define DEBUG(x) printf("ERROR: %s \n", x);
using namespace std;
int main()
{

	cMenu *mainWidget = new cMenu();
	DEBUG("Point 0");
	getch();
	string sInput;
	cin >> sInput;
	DEBUG("point xy");
//	cout << "msg to be displayed" << sInput << endl;
//	initscr();
	DEBUG("Point T");
	getch();
	while(sInput != string("quit"))
	{
		DEBUG("Point Z");
		mainWidget->addToMenu(sInput);
		cin >> sInput;
	}
	DEBUG("Point X");
	initscr();

	mainWidget->show();
	endwin();
}
