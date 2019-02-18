#ifndef CLISTBOX_H_INCLUDED
#define CLISTBOX_H_INCLUDED
#include "Controls.h"

class CListBox : public Controls
{
public:
    CListBox(){}
    ~CListBox(){}
    void Create(const HWND hWndParent, int x, int y, int w, int h,
            int id, LPCSTR txt = "");

    int AddItem(const char* text_in) const;
    int GetItemText(int index, char* text);
    int GetSelTextLen();
    int GetSelText(char* text);
    int GetSelInt();
    float GetSelFloat();
};

#endif // CLISTBOX_H_INCLUDED
