#include"Window.h"
#include"TextButton.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window wnd;
	//create
	//CreateWindowEx(0, "Button", "But", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 0, 0, 200, 100, wnd.window_handle, nullptr, hInstance, nullptr);
	
	TextButton tb(wnd, "But", 0, 0, 200, 100);
	tb.OnClick = [](TextButton& button)
	{
		MessageBox(nullptr, "Clicked", "Info", MB_OK);
	};

	while(wnd.IsOpen())
	{
		wnd.ProcessEvents();
	}
	return 0;
}