#include <Windows.h>

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);
	wc.hInstance = hInstance;
	//wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = TEXT("WINDOW");
	wc.lpszMenuName = NULL;
	wc.style = 0;

	RegisterClass(&wc);

	HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("TEXT WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	/*
	HWND        hwnd;
    UINT        message;
    WPARAM      wParam;
    LPARAM      lParam;
    DWORD       time;
    POINT       pt;
	*/
	MSG msg;
	while (1)
	{
		if (GetMessage(&msg, NULL, 0, 0) == FALSE)
		{
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}