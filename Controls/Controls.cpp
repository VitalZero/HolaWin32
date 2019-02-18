#include "Controls.h"
#include <string>

Controls::Controls()
    :
    hWnd(nullptr),
	x(0), y(0),
	width(0), height(0)
{
}

void Controls::Resize(int w, int h) const
{
	SetWindowPos(hWnd, NULL, 0, 0, w, h, SWP_NOMOVE | SWP_NOZORDER);
}

void Controls::Move(int x, int y) const
{
	SetWindowPos(hWnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void Controls::GetText(LPTSTR lpText) const
{
    GetWindowText(hWnd, lpText, TextLength() + 1);
}

void Controls::SetFocus() const
{
    ::SetFocus(hWnd);
}
/*
std::string Controls::GetText()
{
    const int size = TextLength();
    TCHAR temp[size];
    GetWindowText(hWnd, temp, size);

    const std::string strTemp(temp);

    return strTemp;
}
*/
int Controls::TextLength() const
{
    return GetWindowTextLength(hWnd) + 1;
}

void Controls::SetText(LPCTSTR controlText)
{
	BOOL lr;
	lr = SetWindowText(hWnd, controlText);
	assert(lr == TRUE);
}
