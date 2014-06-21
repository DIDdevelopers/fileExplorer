#include "menuWidget.h"
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
	box(m_Window, 0, 0);
	wmove(m_Window, 1, 1);
	set_menu_win(m_Menu, m_Window);
	set_menu_sub(m_Menu, derwin(m_Window, 6, 38, 3 ,1));
	set_menu_mark(m_Menu, "*");
	
	post_menu(m_Menu);
	wrefresh(m_Window);
}


void cMenu::addToMenu(string sItem)
{
	for(int i = 0; i < MENU_MAX; i++)
	{
		if(m_Items[i] == NULL)
		{
			m_Items[i] = new_item(sItem.c_str(), "");
			m_Items[i + 1] = NULL;
			break;
		}
	}
}
