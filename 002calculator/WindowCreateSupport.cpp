
#include "WindowCreateSupport.h"

namespace WndCreateSupport {

	//0으로 초기화
	unsigned __int16 win::StackedPrimaryNumber = 0x00;
	unsigned long win::WindowLength = 1;


	std::vector<void*> win::WindowCollector;

	win::win(void) {
		printf("Create new window instance\n");
		win::WindowCollector.push_back(this);
		win::WindowLength = win::WindowCollector.size();
		printf("- - - Now total count: %d Window instances\n", win::WindowLength);
	};
	win::~win(void) {

	};

	//void win::ReadyProcFn(LRESULT* CALLBACK fn_ptr) {
	//	this->ProcedurePtrFn = fn_ptr;
	//};

	//LRESULT* CALLBACK win::GetProcFn() {
	//	return this->ProcedurePtrFn;
	//};


	void win::on(IMMEDIATE_LIVE_HOOK Type, void* Callback) {
		this->HookStorage.push_back(Type);
		this->HookStorageLength = this->HookStorage.size();
		// Callback(0);
	};

	void win::ImmediateLiveUpdate() {
		//STATICALLY
		
		//IMMEDIATELY
		int ImmediateCnt=0;
		for (void* Callback : this->HookStorage_ptr) {
			//printf("%d\n", Type);
			//Callback();
			ImmediateCnt++;
		};

		//delete &ImmediateCnt;
	};

	const __int16 win::RandomizeNumber(int a,int b, int length) {
		return 0x00;
	};
	const __int16 win::TakeItYourUniqueNumber_16bit() {
		return 0x00;
	};
	
	//메세지박스를 그대로 쓰고싶어서 클레스 안으로 집어넣음 엌
	void win::WindowClassRegister(WNDCLASS& WndClassOptions) {
		if (!RegisterClass(&WndClassOptions)) {
			MessageBoxOpen(L"Failed!", L"WNDCLASS Registration failed!");
		};
	};

	void win::MessageBoxOpen(LPCWSTR Caption, LPCWSTR Text) {
		MessageBox(NULL,Text,Caption, MB_OK);
	};
	void win::MessageBoxOpen(LPCWSTR Caption, LPCWSTR Text, UINT Style) {
		MessageBox(NULL, Text, Caption, Style);
	};

	void win::SetLpClassName(LPCWSTR lpClassName) {
		this->lpClassName = lpClassName;
	};
	LPCWSTR win::GetLpClassName() {
		return this->lpClassName;
	};
	LPCWSTR* win::GetLpClassName_ptr() {
		return &this->lpClassName;
	};


	void win::SetPos(int x,int y) {
		this->PosX = x;
		this->PosY = y;
	};
	void win::UpdatePos(int x, int y) {

	};
	const int* win::GetPos() {
		int dump[1];
		dump[0] = this->PosX;
		dump[1] = this->PosY;
		return dump;
	};


	void win::SetSize(int x, int y) {
		this->Width = x;
		this->Height = y;
	};
	void win::UpdateSize(int x, int y) {

	};
	const int* win::GetSize() {
		int dump[1];
		dump[0] = this->Width;
		dump[1] = this->Height;
		return dump;
	};


	void win::SetText(LPCWSTR Text) {
		this->Text = Text;
	};
	void win::UpdateText(LPCWSTR Text) {

	};
	LPCWSTR win::GetText() {
		return this->Text;
	};

	void win::SetStyle(DWORD Style) {
		this->Style = Style;
	};
	void win::UpdateStyle(DWORD Style) {

	};
	DWORD win::GetStyle() {
		return this->Style;
	};

	void win::SetMenu(HMENU Menu) {
		this->Menu = Menu;
	};
	HMENU win::GetMenu() {
		return this->Menu;
	};

	void win::SethInstance(HINSTANCE hInstance) {
		this->hInstance = hInstance;
	};

	HWND& win::GetHandle() {
		return this->ProcessHandle;
	};
	HWND& win::GetParentHandle() {
		return this->ParentHandle;
	};

	void win::WndShow() {
		ShowWindow(this->ProcessHandle,0);
		___dummy_text((char*)"Show window");
	};

	void win::WndUpdate() {
		UpdateWindow(this->ProcessHandle);
		___dummy_text((char*)"Update window");
	};

	void win::make() {

	};
	void win::destroy() {

	};
	void win::stop() {

	};
	void win::resume() {

	};

	void win::___dummy_text(void* dummy) {
		if (this->dwThreadID) {
			printf("ID: %d (%s)\n",this->dwThreadID,dummy);
		} else {
			printf("ID: 0 (%s)\n", dummy);
		}
		
	}

	unsigned int __stdcall win::StaticThreadEntry(void *args) {
		win* p = static_cast<win*>(args);
		return p->ThreadFunction(NULL);
	};
	INT CALLBACK win::ThreadFunction(void* args) {

		this->ProcessHandle = CreateWindow(
			this->lpClassName,
			this->Text,
			this->Style,
			this->PosX,
			this->PosY,
			this->Width,
			this->Height,
			this->ParentHandle,
			this->Menu,
			this->hInstance,
			this->lpParam
		);
		if (!this->ProcessHandle) {
			MessageBoxOpen(L"Failed!", L"Handle make failed!");
		}
		___dummy_text((char*)"Created Window");



		//로컬 메세지
		bool bDone = false;
		MSG msg;
		while (!bDone)
		{
			while (PeekMessage(&msg, this->ProcessHandle, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					bDone = true;
				} else {
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				//등록된 이벤트 확인 루프
				this->ImmediateLiveUpdate();
			}
			
			InvalidateRect(this->ProcessHandle, NULL, TRUE);
			UpdateWindow(this->ProcessHandle);
		}



		return (int)msg.wParam;


	}
	void win::Error(const char* mes) {
		printf("Custom Error occurred: %s", mes);
		exit(0);
	}

	void win::init() {
		this->hThread = (HANDLE)_beginthreadex(
			NULL,
			0,
			&win::StaticThreadEntry,
			this,
			(unsigned int)0,
			(unsigned int*)&this->dwThreadID
			
		);
		if (this->hThread == 0) Error("_beginthreadex Error\n");
		___dummy_text((char*)"Created thread handle");
		//printf("Created thread handle ID : %d\n", this->hThread);
		//printf("Created thread ID : %d\n", this->dwThreadID);
		//WaitForSingleObject(this->hThread, INFINITE);
	};
};
