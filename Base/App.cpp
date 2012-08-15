/* App.cpp
 * written by konlil
 *
 * ����ļ��ͳ����ļ������ɲ���ϵͳ��ͼ���豸��Ӧ�ýӿڼ����ڹ�����
 */

#include "Main.h"

struct AppState
{
	GraphicsDevice* 	graphics;
	FrameTimer		timer;
	Vec2i			dimensions;
	ApplicationWindow	window;
	InputMananger		input;
}

class App
{
public:
	void Init(HINSTANCE hInstance, int nCmdShow);
	void MessageLoop(HINSTANCE hInstance, int nCmdShow);

	void FreeMemory();

	void RenderFrame();

private:
	AppState	_state;
	Controller*	_controller;
}
