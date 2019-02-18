#ifndef CWINDOW_H
#define CWINDOW_H

#include "CFrame.h"
#include "../Controls/CListBox.h"
#include "../Controls/CLabel.h"

#define IDC_DESGLOSE 1200

class CWindow : public CFrame
{
public:
    CWindow()
        :
        hLib(nullptr)
    {
    }
    ~CWindow()
    {
    }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
    HMODULE hLib;

protected:
    CListBox lbList;
    const char* ClassName() { return "SampleClass"; }
    void OnDestroy(HWND in_hWnd);
	int OnPaint(HWND hWndP);
	BOOL OnCreate(HWND hWnd_in, LPCREATESTRUCT);
	HBRUSH OnCtlColorStatic(HWND hWndP, HDC hdc, HWND hWndCtl, int color);
	BOOL OnCommand(HWND hWndP, int id, HWND hWndCtl, UINT notifyCode);
};

#endif // CWINDOW_H
