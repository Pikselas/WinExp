#include "Window.h"
#include"TextButton.h"
#include"RangeButton.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    Window wnd;
	TextButton btn(wnd, "Button", 100, 100, 100, 100);
	RangeButton btn2(wnd, 0,10, 100, 200, 100, 100);

	btn.OnClick = [&](TextButton& b)
		{
		SetWindowText(wnd.window_handle, "Button Clicked");
		};
	btn2.OnSlide = [&](RangeButton& b)
	{
		SetWindowText(wnd.window_handle, std::to_string(b.GetCurrentPos()).c_str());
	};
	
    while (wnd.IsOpen())
    {
		wnd.ProcessEvents();
    }
	return 0;
}