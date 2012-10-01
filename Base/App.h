/* App.h
 * written by konlil
 *
 * 入口文件和出口文件，集成操作系统，图形设备，应用接口及窗口管理器
 */

#include "Main.h"


struct AppState
{
	//GraphicsDevice* 	graphics;
	//FrameTimer		timer;
	Vec2i				dimensions;
	AppWindow			window;
	InputManager		input;
};

class App
{
public:
	void Init(HINSTANCE hInstance, int nCmdShow);
	void MessageLoop(HINSTANCE hInstance, int nCmdShow);

	void FreeMemory();

	void RenderFrame();

private:
	AppState	_state;
	//Controller*	_controller;
};
