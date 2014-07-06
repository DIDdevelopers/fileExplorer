#ifndef WID_H
#define WID_H
#include "wid.h"
#endif
using namespace std;

class cSearchWidget:public cWidget
{
public:
	cSearchWidget(int nHeight, int nWidth, int nX, int nY):cWidget(nHeight, nWidth, nX, nY)
	{
	}
	bool onKeyPressed(int nKey);
	void setText(string sText);
private:
	string m_sSearch;
	int m_nPosition;
};
