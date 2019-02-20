#ifndef CLISTVIEW_H_INCLUDED
#define CLISTVIEW_H_INCLUDED

#include "Controls.h"
#include <commctrl.h>

class CListView : public Controls
{
public:
    CListView(int style_in = LVS_LIST)
        :
        style(style_in),
        lvc({0}),
        lvi({0})
    {}
    ~CListView(){}

    void Create(const HWND hWndParent, int x, int y, int w, int h,
						int id, LPCSTR txt = "");
    int InsertItem(const char* text, int index_in = 0);
    void AddColumn(const char* text, int width_in = 100);
    BOOL SetSubItem(const char* text, int subItem_in, int index_in);
    BOOL SetSubItem(const char* text, int subItem_in);
    void SetExStyle(int exStyle_in);

public:
    class SubItem
	{
    	SubItem(int subItem_in);
	};
private:
    int style;
    int columnCount = 0;
    int currItem = -1;
    int itemCount = 0;
    LVCOLUMN lvc;
    LVITEM lvi;

private:
    void InitColumns();
};


#endif // CLISTVIEW_H_INCLUDED
