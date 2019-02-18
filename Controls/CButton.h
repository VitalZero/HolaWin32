#ifndef CBUTTON_H
#define CBUTTON_H
#include "Controls.h"

// Button
class CButton : public Controls
{
public:
	CButton(bool isDefault);
	~CButton(){}
	void Create(const HWND hWndParent, int x, int y, int w, int h,
				int id, LPCTSTR txt = "");
    HWND Window() const { return hWnd;}
protected:
	bool defPush;
};

#endif // CBUTTON_H
