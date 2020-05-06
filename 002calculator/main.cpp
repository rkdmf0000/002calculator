#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#include "common.h"
#include "calculator.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	calculatorStart(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
	return 0;
};


