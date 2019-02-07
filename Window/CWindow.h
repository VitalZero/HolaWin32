#ifndef CWINDOW_H
#define CWINDOW_H


#include "CFrame.h"
/*
#include "Controls.h"
#include "CEdit.h"
#include "CButton.h"
#include "CLabel.h"
*/

#define IDC_DESGLOSE 1200

class CWindow : public CFrame
{
public:
    CWindow()
        :
        hLib(nullptr),
        hFont(nullptr)
    {
    }
    ~CWindow()
    {
        UnregisterClass(ClassName(), hInst);
        ReleaseDC(hWnd, hdc);
        DeleteObject(hFont);
    }

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
    // VARIABLES
    HMODULE hLib;
    HFONT hFont;
    // CONTROLES
protected:
    //FUNCIONES
    const char* ClassName() { return "SampleClass"; }
    void OnDestroy(HWND in_hWnd);
	int OnPaint(HWND hWndP);
	BOOL OnCreate(HWND in_hWnd, LPCREATESTRUCT);
	HBRUSH OnCtlColorStatic(HWND hWndP, HDC hdc, HWND hWndCtl, int color);
	BOOL OnCommand(HWND hWndP, int id, HWND hWndCtl, UINT notifyCode);
	void OnBtnDesglose();
};

#endif // CWINDOW_H
