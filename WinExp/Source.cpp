#include "Window.h"
#include"RangeButton.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    Window wnd;
	RangeButton range_button(wnd, 10,100, 0, 0, 500, 70);
	range_button.OnSlide = [&](RangeButton& range_button)
	{
		SetWindowText(wnd.window_handle, std::to_string(range_button.GetCurrentPos()).c_str());
	};
    while (wnd.IsOpen())
    {
		wnd.ProcessEvents();
    }
	return 0;
}