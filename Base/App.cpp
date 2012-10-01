/* App.cpp
 * written by konlil
 *
 * 入口文件和出口文件，集成操作系统，图形设备，应用接口及窗口管理器
 */

#include "Main.h"

const int WindowWidth = 800;
const int WindowHeight = 600;


void App::Init(HINSTANCE hInstance, int nCmdShow)
{
	const char* s = "kexe";
	const String& windowName = s;

	AllocConsole();

	//_state.graphics = NULL;

	g_WndProcContext = &_state.input;
	_state.window.InitAll(hInstance, nCmdShow, false, WindowWidth, WindowHeight, windowName);

}

void App::RenderFrame()
{
}

void App::MessageLoop(HINSTANCE hInstance, int nCmdShow)
{
	MSG msg;
	BOOL bGotMsg;

	PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);

	while( WM_QUIT != msg.message)
	{
		bGotMsg = PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE);
		if (bGotMsg)
		{
			//String s = String(msg.message);
			//Console::WriteLine(s);

			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else
		{
			RenderFrame();
		}
	}
}

void App::FreeMemory()
{
	_state.window.FreeMemory();
}
