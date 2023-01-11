#include "Window.h"
#include"TextButton.h"
#include"RangeButton.h"
#include"TextEntry.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    Window wnd;
	RangeButton range_button(wnd, 0, 10, 100, 100, 100, 50);
	TextEntry entry(wnd, 10, 10, 500, 50);
	range_button.OnSlide = [&](RangeButton& button)
	{
		entry.SetText(std::to_string(button.GetCurrentPos()));
	};
    while (wnd.IsOpen())
    {
		wnd.ProcessEvents();
    }
	return 0;
}