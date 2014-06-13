#include "widget.h"
#include <string>
using namespace std;
#define MENU_MAX 10

class cMenu:protected cWidget
{
public:
	cMenu():cWidget(LINES, COLS, 0, 0)
	{
		cout << "inside default constructor" << endl;
		m_Items = (ITEM **)calloc( 10, sizeof(ITEM *));
		printf("Base arry %p\n", m_Items);
		m_Items[0] = NULL;
		printf("%p\n", m_Items);
		printf("%p\n", m_Items[0]);
		getch();
		
	}
	cMenu(int nHeight, int nWidth, int nX, int nY):cWidget(nHeight, nWidth, nX, nY)
	{
		cout << "inside parameterized constructor" << endl;
		m_Items = (ITEM **)calloc( 10, sizeof(ITEM *));
		m_Items[0] = NULL;
	}
	virtual void show();
	void addToMenu(std::string sItem);

private:
	ITEM **m_Items;
	MENU *m_Menu;
};
