#include "menu.h"
#include <string>
#define DEBUG(x) printf("ERROR: %s \n", x);
using namespace std;
void cMenu::show()
{
	if(!m_Window)
	{
		m_Window = newwin(m_nHeight, m_nWidth, m_nY, m_nX);
	}
	
	m_Menu = new_menu(m_Items);
//	post_menu(m_Menu);
	set_menu_win(m_Menu, m_Window);
	set_menu_mark(m_Menu, "*");
	box(m_Window, '+', '+');
	post_menu(m_Menu);
	wrefresh(m_Window);
	refresh();
}


void cMenu::addToMenu(string sItem)
{
	printf("%p", m_Items);
	DEBUG("before adding to menu");
	getch();
	for(int i = 0; i < MENU_MAX; i++)
	{
		if(m_Items[i] == NULL)
		{
			DEBUG("adding new menu");
			getch();
			m_Items[i] = new_item(sItem.c_str(), sItem.c_str());
			m_Items[i + 1] = NULL;
			DEBUG("After adding to new menu");
			getch();
			break;

		}
	}
}
