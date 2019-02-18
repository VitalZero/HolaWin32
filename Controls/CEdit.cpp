#include "Cedit.h"
#include <cstdlib>

// Edit Box
int CEdit::GetInt()
{
    const int tempSize = TextLength();

    if(tempSize - 1 == 0)
    {
        return 0;
    }
    else
    {
        char buffer[tempSize];

        GetWindowText(hWnd, buffer, tempSize);

        return std::atoi(buffer);
    }
}

float CEdit::GetFloat()
{
    const int tempSize = TextLength();

    if(tempSize - 1 == 0)
    {
        return 0.0f;
    }
    else
    {
        char buffer[tempSize];

        GetWindowText(hWnd, buffer, tempSize);

        return (float)std::atof(buffer);
    }
}

bool CEdit::IsEmpty() const
{
    if(GetWindowTextLength(hWnd) == 0)
        return true;

    return false;
}

void CEdit::Create(const HWND hWndParent, int x, int y, int w, int h, int id, LPCTSTR txt)
{

	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", txt,
					  WS_VISIBLE | WS_CHILD | ES_LEFT | WS_TABSTOP | WS_GROUP ,
					  x, y, w, h, hWndParent, (HMENU)id, GetModuleHandle(NULL), NULL);

	assert(hWnd != NULL);
}
