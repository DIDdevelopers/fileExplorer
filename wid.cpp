#include "wid.h"

void cWidget::show()
{
	if(!m_Window)
	{
		m_Window = newwin(m_nHeight, m_nWidth, m_nY, m_nX);
	}
	box(m_Window, '+', '+');
	wrefresh(m_Window);
//	refresh();
}

void cWidget::hide()
{
	clrtoeol();
	delwin(m_Window);
}

void cWidget::print(string sMsg)
{
	box(m_Window, '+', '+');
	int nX = getcurx(m_Window);
	int nY = getcury(m_Window);
	mvwprintw(m_Window, ++nY, 2, "%s", sMsg.c_str());
	wrefresh(m_Window);
	refresh();

}

bool cWidget::onKeyPressed(int nKey)
{
}
