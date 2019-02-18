#include "CListBox.h"
#include <cstdlib>

void CListBox::Create(const HWND hWndParent, int x, int y, int w, int h,
        int id, LPCSTR txt)
{
	//int* ptr_int = &id;

	hWnd = CreateWindowEx(0, "ListBox", "",
					  LBS_HASSTRINGS | WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY | WS_VSCROLL,
					  x, y, w, h, hWndParent, (HMENU)&id, GetModuleHandle(NULL), NULL);

	assert(hWnd != NULL);
}

int CListBox::AddItem(const char* text_in) const
{
    return SendMessage(hWnd, LB_ADDSTRING, 0, (LPARAM)text_in);
}

int CListBox::GetItemText(int index, char* text)
{
    return SendMessage(hWnd, LB_GETTEXT, (WPARAM)index, (LPARAM)text);
}

int CListBox::GetSelTextLen()
{
    const int index = (int)SendMessage(hWnd, LB_GETCURSEL, 0, 0);
    return (int)(SendMessage(hWnd, LB_GETTEXTLEN, (WPARAM)index, 0) + 1);
}

int CListBox::GetSelText(char* text)
{
    const int index = (int) SendMessage(hWnd, LB_GETCURSEL, 0, 0);
    // TODO
    // check if text has enough space to store the result, it not, allocate it?
    if(sizeof(text) < (size_t)GetSelTextLen())
        return -1;

    return SendMessage(hWnd, LB_GETTEXT, (WPARAM)index, (LPARAM)text);
}

int CListBox::GetSelInt()
{
    const int itemLen = GetSelTextLen();
    char tmpText[itemLen];

    GetSelText(tmpText);

    return std::atoi(tmpText);
}

float CListBox::GetSelFloat()
{
    const int itemLen = GetSelTextLen();
    char tmpText[itemLen];

    GetSelText(tmpText);

    return (float)std::atof(tmpText);
}

