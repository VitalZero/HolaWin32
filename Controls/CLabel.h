#ifndef CLABEL_H
#define CLABEL_H
#include "Controls.h"

// Label
class CLabel : public Controls
{
public:
	CLabel(){}
	~CLabel(){}
	void Create(const HWND hWndParent, int x, int y, int w, int h,
				int id, LPCTSTR txt = "");
protected:
};

#endif // CLABEL_H
