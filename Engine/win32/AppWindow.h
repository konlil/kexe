/*
 * AppWindow.h
 * written by konlil
 *
 * �����͹������������
 */

class AppWindow
{
public:
	AppWindow();

	void FreeMemory();
	void FreeWindow();
	void Init(HWND handle);
	void InitAll(HINSTANCE hInstance, int nCmdShow, bool _fullScreen, int _ScreenWidth, int _ScreenHeight, const String &WindowName);

	//
	// ��������
	//
	__forceinline HWND Handle() 
	{ 
		return _handle; 
	}
	
	bool	FullScreen()
	{
		return _fullScreen;
	}

	__forceinline double& FixedAspectRatio()
	{
		return _fixedAspectRatio;
	}

private:
	String		_className;
	WNDCLASS	_class;
	HWND		_handle;
	bool		_fullScreen;
	double		_fixedAspectRatio;
};
