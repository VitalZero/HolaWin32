#ifndef CCOMBOBOX_H_INCLUDED
#define CCOMBOBOX_H_INCLUDED
#include "Controls.h"

class CComboBox : public Controls
{
public:
    CComboBox(){}
    ~CComboBox(){}
    void Create(const HWND hWndParent, int x, int y, int w, int h,
				int id, LPCSTR txt = "");
    void AddItem(const char* text_in);
    void GetItemText(char* text);
    int GetItemInt();
    float GetItemFloat();
};


#endif // CCOMBOBOX_H_INCLUDED
