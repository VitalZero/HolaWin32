#ifndef CLISTVIEW_H_INCLUDED
#define CLISTVIEW_H_INCLUDED
#define _WIN32_IE 0x0500
#include "Controls.h"
#include <commctrl.h>

class CListView : public Controls
{
public:
    CListView(int style_in = LVS_LIST)
        :
        style(style_in),
        columns(0),
        items(0),
        lvc({0}),
        lvi({0})
    {}
    ~CListView(){}
    void Create(const HWND hWndParent, int x, int y, int w, int h,
						int id, LPCSTR txt = "");
    int InsertItem(LPSTR text, int index_in = 0);
    void InsertColumn(char* text, int width_in = 100);
    BOOL SetSubItem(char* text, int subItem_in, int index_in = 0);
    void SetExStyle(int exStyle_in);
private:
    int style;
    int columns;
    int items;
    LVCOLUMN lvc;
    LVITEM lvi;

private:
    void InitColumns();
};


#endif // CLISTVIEW_H_INCLUDED
