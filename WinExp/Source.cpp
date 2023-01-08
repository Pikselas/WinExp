#include "Window.h"
#include"RangeButton.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    Window wnd;
	RangeButton range_button(wnd, 0, 0, 500, 70);
    while (wnd.IsOpen())
    {
		wnd.ProcessEvents();
    }
	return 0;
}