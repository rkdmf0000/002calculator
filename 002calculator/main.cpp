#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include "WindowCreateSupport.h"

LRESULT CALLBACK WelcomeWindowProcedure(HWND handle,UINT message, WPARAM wp, LPARAM lp) {
	switch (message) {
	case WM_DESTROY:
		printf("윈도우 종료됨\n");
		
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(handle, message, wp, lp));
};


int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	const wchar_t WelcomeWindowClassName[] = L"CWelcomeWindowClassName";

	WNDCLASS WelcomeWindow;
	WelcomeWindow.lpfnWndProc = WelcomeWindowProcedure;
	WelcomeWindow.lpszClassName = WelcomeWindowClassName;
	WelcomeWindow.cbClsExtra = NULL;
	WelcomeWindow.cbWndExtra = NULL;
	WelcomeWindow.lpszMenuName = NULL;
	WelcomeWindow.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WelcomeWindow.hCursor = (HCURSOR)LoadCursor(NULL, IDC_ARROW);
	WelcomeWindow.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WelcomeWindow.hInstance = hInstance;
	WelcomeWindow.style = CS_HREDRAW | CS_VREDRAW;

	WndCreateSupport::win* window = new WndCreateSupport::win;
	window->WindowClassRegister(WelcomeWindow);

	window->SetPos(100, 100);
	window->SetSize(500, 500);
	window->SetStyle(WS_OVERLAPPEDWINDOW|WS_VISIBLE);
	window->SetText(L"Idiot-윈도우1");
	window->SetLpClassName(WelcomeWindowClassName);
	window->SethInstance(hInstance);
	window->init();


	WndCreateSupport::win* windowx = new WndCreateSupport::win;
	windowx->SetPos(200, 200);
	windowx->SetSize(500, 500);
	windowx->SetStyle(WS_OVERLAPPEDWINDOW | WS_VISIBLE);
	windowx->SetText(L"Idiot-윈도우2");
	windowx->SetLpClassName(WelcomeWindowClassName);
	windowx->SethInstance(hInstance);
	windowx->init();




	while (1) { Sleep(65800000); }
};


