#include "searchInput.h"


bool cSearchWidget::onKeyPressed(int nKey)
{
	int nSize = 0;
	switch(nKey)
	{
	case KEY_BACKSPACE:
		nSize = m_sSearch.size();
		m_sSearch.resize(nSize - 1);
		break;
	default:
		break;
       
	}       
	return(1);
}

void cSearchWidget::setText(string sText)
{
	mvwprintw(m_Window, 1, 1, sText.c_str());
	int nX = getcurx(m_Window);
	int nY = getcury(m_Window);
	wmove(m_Window, nY, nX + sText.size());
	wrefresh(m_Window);
	refresh();
}
