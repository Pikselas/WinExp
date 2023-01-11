#include "Window.h"
#include"TextButton.h"
#include"RangeButton.h"
#include"TextEntry.h"
#include"Label.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    Window wnd;
	RangeButton range_button(wnd, 0, 10, 100, 100, 100, 50);
	Label lb(wnd,"Label", 10, 10, 500, 50);
	range_button.OnSlide = [&](RangeButton& button)
	{
		lb.SetText(std::to_string(button.GetCurrentPos()));
	};
    while (wnd.IsOpen())
    {
		wnd.ProcessEvents();
    }
	return 0;
}