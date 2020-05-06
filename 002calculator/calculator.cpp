
#include "calculator.h"

void MousePosDisplay(HWND& handle, UINT& message, WPARAM& wp, LPARAM& lp) {
	short mx, my;
	mx = (short)LOWORD(lp);
	my = (short)HIWORD(lp);


	std::wstring strx, stry;
	strx = std::to_wstring(mx);
	stry = std::to_wstring(my);

	const wchar_t* chx;
	const wchar_t* chy;
	chx = strx.c_str();
	chy = stry.c_str();

	HDC hDC = GetDC(handle);
	Rectangle(hDC, 18, 18, 60, 58);
	TextOut(hDC, 20, 20, L"x:", 2);
	TextOut(hDC, 30, 20, chx, _tcslen(chx));
	TextOut(hDC, 20, 40, L"y:", 2);
	TextOut(hDC, 30, 40, chy, _tcslen(chy));
	ReleaseDC(handle, hDC);
}


void WindowPosDisplay(HWND& handle, UINT& message, WPARAM& wp, LPARAM& lp) {

};




LRESULT CALLBACK WelcomeWindowProcedure(HWND handle, UINT message, WPARAM wp, LPARAM lp) {
	//RECT rect{ 20,20,30,20 };

	switch (message) {

	case WM_MOUSEMOVE:
		MousePosDisplay(handle, message, wp, lp);
		return 0;

	case WM_ACTIVATE:
		printf("WM_ACTIVATE ON: %d/%d\n", wp, lp);
		return 0;
	case WM_COPY:
		printf("WM_COPY ON\n");
		return 0;

	case WM_KEYUP:
		printf("WM_KEYUP ON: %d/%d\n", wp, lp);
		//SendMessage(handle, WM_COPY, (WPARAM)L"fucker", NULL);
		return 0;
	case WM_KEYDOWN:
		printf("WM_KEYDOWN ON: %d/%d\n", wp, lp);
		return 0;
	case WM_COMMAND:
		printf("WM_COMMAND ON\n");
		return 0;
	case WM_PAINT:
		//InvalidateRect(handle, &rect, true);
		//printf("WM_PAINT ON\n");
		return 0;

	case WM_ENABLE:
		printf("WM_ENABLE ON\n");
		return 0;

	case WM_CREATE:
		printf("WM_CREATE ON\n");
		return 0;


	case WM_DESTROY:
		printf("윈도우 종료됨\n");

		PostQuitMessage(0);
		return 0;
		break;
	}
	return (DefWindowProc(handle, message, wp, lp));
};
void calculatorStart(const HINSTANCE& hInstance, const HINSTANCE& hPrevInstance, const LPSTR& lpCmdLine, const int& nCmdShow) {
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
	window->SetStyle(WS_OVERLAPPEDWINDOW | WS_VISIBLE);
	window->SetText(L"Idiot 윈도우1");
	window->SetLpClassName(WelcomeWindowClassName);
	window->SethInstance(hInstance);
	window->init();


	WndCreateSupport::win* windowx = new WndCreateSupport::win;
	windowx->SetPos(100, 600);
	windowx->SetSize(600, 200);
	windowx->SetStyle(WS_OVERLAPPED | WS_BORDER | WS_VISIBLE);
	windowx->SetText(L"Idiot 윈도우2");
	windowx->SetLpClassName(WelcomeWindowClassName);
	windowx->SethInstance(hInstance);

	windowx->init();


	windowx->on(WndCreateSupport::IMMEDIATE_LIVE_HOOK::IMMEDIATE_LIVE_HOOK__MOUSE_CLICK,([](){
		printf("helo\n");
	}));


	//안죽이고 계속 살아있게 하는것
	while (1) { Sleep(65800000); }
};