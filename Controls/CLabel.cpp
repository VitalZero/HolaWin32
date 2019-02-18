#include "CLabel.h"

// Label
void CLabel::Create(const HWND hWndParent, int x, int y, int w, int h, int id, LPCTSTR txt)
{
	hWnd = CreateWindowEx(WS_EX_TRANSPARENT, "STATIC", txt,
					  WS_VISIBLE | WS_CHILD | SS_LEFT /*| WS_BORDER*/,
					  x, y, w, h, hWndParent, (HMENU)id, GetModuleHandle(NULL), NULL);

	assert(hWnd != NULL);
}
