#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#include "_002CalculatorWindowCreateSupport.h"


LRESULT CALLBACK WelcomeWindowProcedure(HWND handle,UINT message, WPARAM wp, LPARAM lp) {
	switch (message) {
	case WM_DESTROY:
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

	mod::win* window = new mod::win;
	window->WindowClassRegister(WelcomeWindow);

	window->SetPos(100, 100);
	window->SetSize(500, 500);
	window->SetStyle(WS_OVERLAPPEDWINDOW|WS_VISIBLE);
	window->SetText(L"Idiot-윈도우1");
	window->SetLpClassName(WelcomeWindowClassName);
	window->SethInstance(hInstance);
	window->make();
	//window->WndShow();
	//window->WndUpdate();
	window->init();


	mod::win* windowx = new mod::win;
	windowx->SetPos(200, 200);
	windowx->SetSize(500, 500);
	windowx->SetStyle(WS_OVERLAPPEDWINDOW | WS_VISIBLE);
	windowx->SetText(L"Idiot-윈도우2");
	windowx->SetLpClassName(WelcomeWindowClassName);
	windowx->SethInstance(hInstance);
	windowx->make();
	windowx->WndShow();
	windowx->WndUpdate();
	windowx->init();


	MSG Message;
	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	};
	return (int)Message.wParam;
};


