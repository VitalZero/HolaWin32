#include "CListView.h"
#include <cstdio>

void CListView::Create(const HWND hWndParent, int x, int y, int w, int h,
                    int id, LPCSTR txt)
{
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW,
    		"", WS_VISIBLE | WS_CHILD | style | LVS_EDITLABELS,
			x, y, w, h, hWndParent, (HMENU)id, GetModuleHandle(NULL), NULL);

	assert(hWnd != NULL);

}

void CListView::InsertColumn(char* text, int width_in)
{
    lvc.mask = LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	lvc.cx = width_in;

	lvc.iSubItem = columns;
	lvc.pszText = text;
	SendMessage(hWnd, LVM_INSERTCOLUMN, columns, (LPARAM)&lvc);

    ++columns;
}

int CListView::InsertItem(LPSTR text, int index_in)
{
    lvi.pszText   = text;
    lvi.mask      = LVIF_TEXT | LVIF_STATE;
    lvi.stateMask = 0;
    lvi.iSubItem  = 0;

    lvi.iItem = index_in;

    ++items;

    return SendMessage(hWnd, LVM_INSERTITEM, 0, (LPARAM)&lvi);
}

BOOL CListView::SetSubItem(char* text, int subItem_in, int index_in)
{
    lvi.pszText   = text;
    lvi.mask      = LVIF_TEXT | LVIF_STATE;
    lvi.stateMask = 0;
    lvi.iSubItem  = subItem_in;
    lvi.state     = 0;
    lvi.iItem = index_in;

    return SendMessage(hWnd, LVM_SETITEM, 0, (LPARAM)&lvi);
}

void CListView::SetExStyle(int exStyle_in)
{
    SendMessage(hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, exStyle_in, exStyle_in);
}
