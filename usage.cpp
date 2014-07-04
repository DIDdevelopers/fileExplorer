#include "menuWidget.h"
#include "searchInput.h"
#include <ncurses.h>
#include <iostream>
#include <string>
#include "findex.h"
#include <vector>
#define SEARCH_HT 3

#define DEBUG(x) printf("ERROR: %s \n", x);
using namespace std;
int main()
{
	initscr();
	cbreak();
	keypad(stdscr, 1);
	noecho();
	refresh();

	cSearchWidget *pSearch = new cSearchWidget(SEARCH_HT, COLS, 0, 0);
	cMenu *pMenu = new cMenu(LINES - SEARCH_HT + 1, COLS, 0, SEARCH_HT);
	pSearch->show();
//	pMenu->show();
	cFileIndexer *pIndexer = new cFileIndexer("/home/abhijeet/music");
	pIndexer->createIndex();
	vector<string> vResult = pIndexer->searchIndex("arth");
	for(vector<string>::iterator iter = vResult.begin(); iter < vResult.end(); iter++)
	{
		pMenu->addToMenu( *iter );
	}
	pMenu->show();
/*	
	int nIn = wgetch(pSearch->getWindow());
	while(nIn != 'q')
	{
		pMenu->onKeyPressed(nIn);
		
		nIn = wgetch(pSearch->getWindow());
	}
*/
	getch();
	endwin();
}
