#include"Window.h"
#include"TextButton.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window wnd;
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