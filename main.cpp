/*
 * main.cpp
 *
 *  Created on: 31 ene 2019
 *      Author: jmichel
 */

#define WIN32_LEAN_AND_MEAN
#include "Window/CWindow.h"
#include <commctrl.h>


int CALLBACK WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmdLine, int nCmdShow)
{
    InitCommonControls();

    CWindow win;

	if(!win.Create("Prueba de ventana", WS_OVERLAPPEDWINDOW))
	{
		return 0;
	}
	win.ResizeWindow(400, 300);
	win.Show(nCmdShow);

    return win.Run();
}


