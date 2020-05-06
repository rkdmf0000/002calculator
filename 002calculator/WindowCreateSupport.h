
#include "common.h"
namespace WndCreateSupport {

	/**
		*	TITLE	IMMEDIATE LIVE HOOK
		*	DESC	Customized on window events
		*	TYPE	Enum
		*/
	enum class IMMEDIATE_LIVE_HOOK {
		//Triggered when window moving
		IMMEDIATE_LIVE_HOOK__WINDOW_MOVE,
		//Triggered when window left click before
		IMMEDIATE_LIVE_HOOK__WINDOW_LEFT_CLICK,
		//Triggered when window left click after
		IMMEDIATE_LIVE_HOOK__WINDOW_LEFT_CLICKED,
		//Triggered when widnow right click
		IMMEDIATE_LIVE_HOOK__WINDOW_RIGHT_CLICK,
		//Triggered when widnow right clicked
		IMMEDIATE_LIVE_HOOK__WINDOW_RIGHT_CLICKED,
		//Triggered when custom button click
		IMMEDIATE_LIVE_HOOK__WINDOW_OTHER_CLICK,
		//Triggered when custom button clicked
		IMMEDIATE_LIVE_HOOK__WINDOW_OTHER_CLICKED,
		//Triggered when mouse move
		IMMEDIATE_LIVE_HOOK__MOUSE_MOVE,
		//Triggered when mouse click before
		IMMEDIATE_LIVE_HOOK__MOUSE_CLICK,
		//Triggered when mouse click after
		IMMEDIATE_LIVE_HOOK__MOUSE_CLICKED,
		//Triggered when window title change
		IMMEDIATE_LIVE_HOOK__TITLE_CHANGED,
		//Triggered when some update request
		IMMEDIATE_LIVE_HOOK__UPDATED,
		//Triggered when window minimize
		IMMEDIATE_LIVE_HOOK__MINIMIZE,
		//Triggered when window maximize
		IMMEDIATE_LIVE_HOOK__MAXIMIZE,
		//Triggered when widnow focus in
		IMMEDIATE_LIVE_HOOK__FOCUS_IN,
		//Triggered when widnow focus out
		IMMEDIATE_LIVE_HOOK__FOCUS_OUT,
		//Triggered when key up on focusing
		IMMEDIATE_LIVE_HOOK__INNER_KEYUP,
		//Triggered when key down on focusing
		IMMEDIATE_LIVE_HOOK__INNER_KEYDOWN,
		//Triggered when key press on focusing
		IMMEDIATE_LIVE_HOOK__INNER_KEYPRESS,
		//Triggered when key up on focus out
		IMMEDIATE_LIVE_HOOK__OUTTER_KEYUP,
		//Triggered when key down on focus out
		IMMEDIATE_LIVE_HOOK__OUTTER_KEYDOWN,
		//Triggered when key press on focus out
		IMMEDIATE_LIVE_HOOK__OUTTER_KEYPRESS
	};

	/*
	*	TITLE	Window API support tool
	*	DESC	A widnow controlled instance by support tool as like noob coder.
	*/



	class win {
	private:

		

		static const unsigned __int16 StackedPrimaryNumberMaximum = UINT16_MAX;
		static unsigned __int16 StackedPrimaryNumber;

		void MessageBoxOpen(LPCWSTR Caption, LPCWSTR Text);
		void MessageBoxOpen(LPCWSTR Caption,LPCWSTR Text,UINT Style);

		std::vector<IMMEDIATE_LIVE_HOOK> HookStorage;
		std::vector<std::function<void()>> HookStorage_ptr;
		unsigned long HookStorageLength = 0;

		const __int16 RandomizeNumber(int a, int b, int length);
		const __int16 TakeItYourUniqueNumber_16bit();

		LPCWSTR lpClassName = NULL;
		LPCWSTR Text = NULL;	
		HWND ProcessHandle = NULL;
		HWND ParentHandle = NULL;
		HINSTANCE hInstance = NULL;
		HMENU Menu = NULL;
		LPVOID lpParam = NULL;
		DWORD Style = NULL;
		int PosX = 0;
		int PosY = 0;
		int Width = 0;
		int Height = 0;
		MSG Message;
		
		/*Thread variables*/
		static unsigned int __stdcall StaticThreadEntry(void *args);
		INT CALLBACK ThreadFunction(void *args);
		void Error(const char* mes);
		HANDLE hThread = NULL;
		DWORD dwThreadID = NULL;
		/*Thread variables end*/

		/*procedure pointer variable*/
		//LRESULT* CALLBACK ProcedurePtrFn;
		/*end*/

		void ImmediateLiveUpdate();
		void ___dummy_text(void* dummy);
		

	public:
		static unsigned long WindowLength;
		static std::vector<void*> WindowCollector;
		win(
			LPCWSTR lpClassName,
			LPCWSTR Text,
			HMENU Menu,
			HINSTANCE hInstance
		);
		win(
			LPCWSTR lpClassName,
			LPCWSTR Text,
			HMENU Menu,
			HINSTANCE hInstance,
			INT posX,
			INT posY,
			INT Width,
			INT Height
		);
		win();
		~win();

		void WindowClassRegister(WNDCLASS& WndClassOptions);
		void SetLpClassName(LPCWSTR lpClassName);

		LPCWSTR GetLpClassName();
		LPCWSTR* GetLpClassName_ptr();
		
		//void ReadyProcFn(LRESULT* CALLBACK fn_ptr);
		//LRESULT* CALLBACK GetProcFn();

		void SetPos(int x, int y);
		void UpdatePos(int x, int y);
		const int* GetPos();
		
		void SetSize(int w, int h);
		void UpdateSize(int w, int h);
		const int* GetSize();
		
		void SetText(LPCWSTR Text);
		void UpdateText(LPCWSTR Text);
		LPCWSTR GetText();

		
		void SetStyle(DWORD Style);
		void UpdateStyle(DWORD Style);
		DWORD GetStyle();
		
		void SetMenu(HMENU Menu);
		HMENU GetMenu();
		//void UpdateMenu(HMENU Menu);

		void SethInstance(HINSTANCE hInstance);

		
		HWND& GetHandle();
		HWND& GetParentHandle();


		void WndShow();
		void WndUpdate();

		void make();
		void destroy();
		void stop();
		void resume();
		void init();

		void on(IMMEDIATE_LIVE_HOOK, std::function<void()>);

	};





	void AttachHook(win instance, IMMEDIATE_LIVE_HOOK HookType, void(*fn));
	void DetachHook(win instance, IMMEDIATE_LIVE_HOOK HookType);




};
