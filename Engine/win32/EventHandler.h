/*
 * EventHandler.h
 * written by konlil
 *
 * define WndProc
 */

extern InputManager *g_WndProcContext;
LRESULT WINAPI WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);	// the windows callback function
