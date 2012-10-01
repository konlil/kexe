/*
 * AppWindow.cpp
 * written by konlil
 *
 * creating and updating the main window
 */

AppWindow::AppWindow()
{
	_handle = NULL;
	_fullScreen = false;
}

void AppWindow::Init(HWND handle)
{
	_handle = handle;
}

void AppWindow::InitAll(HINSTANCE hInstance, int nCmdShow, bool fullScreen, int screenWidth, int screenHeight, const String &windowName)
{
	_className = windowName;

	_class.style = CS_HREDRAW | CS_VREDRAW;
	_class.lpfnWndProc = (WNDPROC)WndProc;
	_class.cbClsExtra = 0;
	_class.cbWndExtra = 0;
	_class.hInstance = hInstance;
	_class.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	_class.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	_class.lpszMenuName = NULL;
	_class.lpszClassName = _className.CString();
	RegisterClass(&_class);

	_fullScreen = fullScreen;
	
	DWORD dwStyle;
	if (fullScreen)
	{
		dwStyle = WS_POPUP;
	}
	else
	{
		dwStyle = WS_OVERLAPPEDWINDOW;
	}

	_handle = CreateWindow(
		windowName.CString(),
		windowName.CString(),
		dwStyle,
		0,
		0,
		screenWidth,
		screenHeight,
		(HWND) NULL,
		(HMENU) NULL,
		hInstance,
		(LPVOID) NULL);

	//PersistentAssert(_handle != NULL, "CreateWindow Failed");

	ShowWindow(_handle, nCmdShow);
	UpdateWindow(_handle);
}	

void AppWindow::FreeMemory()
{
	FreeWindow();
	UnregisterClass(_className.CString(), _class.hInstance);
}

void AppWindow::FreeWindow()
{
	DestroyWindow(_handle);
}
