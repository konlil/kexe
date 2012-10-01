/*
 * WinMain.cpp
 * written by konlil
 *
 * Just create the app and run it
 */

int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	App *a = new App;
	a->Init(hInstance, nCmdShow);
	a->MessageLoop(hInstance, nCmdShow);
	a->FreeMemory();
	delete a;

	return 0;
}
