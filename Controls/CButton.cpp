#include "CButton.h"

// Button
CButton::CButton(bool isDefault)
    :
    defPush(isDefault)
{
}

void CButton::Create(const HWND hWndParent, int x, int y, int w, int h, int id, LPCTSTR txt)
{
	hWnd = CreateWindowEx(0, "BUTTON", txt,
                        WS_VISIBLE | WS_CHILD | BS_CENTER | WS_TABSTOP  |
                        WS_GROUP | (defPush ? BS_DEFPUSHBUTTON : BS_PUSHBUTTON),
                       x, y, w, h, hWndParent, (HMENU)id, GetModuleHandle(NULL), NULL);

	assert(hWnd != NULL);

	//SendMessage(hWnd, BM_SETIMAGE, (WPARAM)IMAGE_ICON, (LPARAM)LoadIcon(NULL, IDI_HAND));
}
