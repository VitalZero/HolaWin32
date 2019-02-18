#include "CComboBox.h"
#include <cstdlib>

void CComboBox::Create(const HWND hWndParent, int x, int y, int w, int h,
            int id, LPCSTR txt)
{

	hWnd = CreateWindowEx(0, "combobox", "",
					  CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
					  x, y, w, h, hWndParent, (HMENU)id, GetModuleHandle(NULL), NULL);

	assert(hWnd != NULL);

}
