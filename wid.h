#include <ncurses.h>
#include <string>

using namespace std;
class cWidget
{
public:
	cWidget(int nHeight, int nWidth, int nX, int nY)
	{
		m_nHeight = nHeight;
		m_nWidth = nWidth;
		m_nX = nX;
		m_nY = nY;
		m_Window = 0;
	}
	cWidget()
	{
		m_nHeight = LINES;
		m_nWidth = COLS;
		m_nX = 0;
		m_nY = 0;
		m_Window = 0;
	}

	void setXY(int x, int y)
	{
		m_nX = x;
		m_nY = y;
	}

	void setHeight(int nHeight)
	{
		m_nHeight = nHeight;
	}
	
	void setWidth(int nWidth)
	{
		m_nWidth = nWidth;

	}					
	WINDOW* getWindow()
	{
		return(m_Window);
	}
	virtual void show();
	void hide();
	void print(string s);
	virtual bool onKeyPressed(int nKey) = 0;
protected:
	int m_nHeight;
	int m_nWidth;
	int m_nX;
	int m_nY;
	WINDOW* m_Window;
};
	
	
