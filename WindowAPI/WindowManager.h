#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#if defined(CURRENT_OS_WINDOWS)
	#include <Windows.h>
#endif

#if defined(CURRENT_OS_LINUX)
	#include <X11/X.h>
	#include <X11/Xlib.h>
	#include <X11/keysym.h>
	#include <string>
#endif

#include "WindowAPI_Defs.h"
#include "Window.h"

class F_W;

class F_WM
{
	friend F_W;

	public:
		F_WM();
		~F_WM();

		//shut down the window manager when your program is finished
		static void ShutDown();

		//get a pointer to a window via name or index
		static F_W* GetWindowByName(const char* a_WindowName);
		static F_W* GetWindowByIndex(GLuint a_WindowIndex);

		//add a window to the manager. i ripped off a behavior tree feature
		//that allows the user to create multiple windows easily
		static F_WM* AddWindow(F_W* a_Window);

		//return the total amount of windows the manager has
		static GLuint GetNumWindows();

		//gets and sets for the mouse position in the screen
		static void GetMousePositionInScreen(GLuint& a_X, GLuint& a_Y);
		static GLuint* GetMousePositionInScreen();
		static void SetMousePositionInScreen(GLuint a_X, GLuint a_Y);

		// get the screen resolution for the screen that is being drawn to
		static GLuint* GetScreenResolution();
		static void GetScreenResolution(GLuint& a_Width, GLuint& a_Height);

		//these are another way to set and get window variables
		//apart from the functions that are available to the user
		//via each window
		
		//sets and gets for window resolution
		static void GetWindowResolution(const char* a_WindowName, GLuint& a_Width, GLuint& a_Height);
		static void GetWindowResolution(GLuint a_WindowIndex, GLuint& a_Width, GLuint& a_Height);
		static GLuint* GetWindowResolution(const char* a_WindowName);
		static GLuint* GetWindowResolution(GLuint a_WindowIndex);
		static void SetWindowResolution(const char* a_WindowName, GLuint a_Width, GLuint a_Height);
		static void SetWindowResolution(GLuint a_WindowIndex, GLuint a_Width, GLuint a_Height);

		//sets and gets for window position
		static void GetWindowPosition(const char* a_WindowName, GLuint& a_X, GLuint& a_Y);
		static void GetWindowPosition(GLuint a_WindowIndex, GLuint& a_X, GLuint& a_Y);
		static GLuint* GetWindowPosition(const char* a_WindowName);
		static GLuint* GetWindowPosition(GLuint a_WindowIndex);
		static void SetWindowPosition(const char* a_WindowName, GLuint a_X, GLuint a_Y);
		static void SetWindowPosition(GLuint a_WindowIndex, GLuint a_X, GLuint a_Y);

		//sets and gets for the mouse position in window
		static void GetMousePositionInWindow(const char* a_WindowName, GLuint& a_X, GLuint& a_Y);
		static void GetMousePositionInWindow(GLuint a_WindowIndex, GLuint& a_X, GLuint& a_Y);
		static GLuint* GetMousePositionInWindow(const char* a_WindowName);
		static GLuint* GetMousePositionInWindow(GLuint a_WindowIndex);
		static void SetMousePositionInWindow(const char* a_WindowName, GLuint a_X, GLuint a_Y);
		static void SetMousePositionInWindow(GLuint a_WindowIndex, GLuint a_X, GLuint a_Y);

		//gets for window keys
		static bool WindowGetKey(const char* a_WindowName, GLuint a_Key);
		static bool WindowGetKey(GLuint a_WindowIndex, GLuint a_Key);

		//gets for window should close
		static bool GetWindowShouldClose(const char* a_WindowName);
		static bool GetWindowShouldClose(GLuint a_WindowIndex);

		//swap buffers
		static void WindowSwapBuffers(const char* a_WindowName);
		static void WindowSwapBuffers(GLuint a_WindowIndex);

		//sets and gets for fullscreen
		static void SetFullScreen(const char* a_WindowName, bool a_NewState);
		static void SetFullScreen(GLuint a_WindowIndex, bool a_NewState);
		static bool GetWindowIsFullScreen(const char* a_WindowName);
		static bool GetWindowIsFullScreen(GLuint a_WindowIndex);

		//gets and sets for minimized
		static bool GetWindowIsMinimized(const char* a_WindowName);
		static bool GetWindowIsMinimized(GLuint a_WindowIndex);
		static void MinimizeWindow(const char* a_WindowName, bool a_NewState);
		static void MinimizeWindow(GLuint a_WindowIndex, bool a_NewState);

		//gets and sets for maximised state
		static bool GetWindowIsMaximized(const char* a_WindowName);
		static bool GetWindowIsMaximized(GLuint a_WindowIndex);
		static void MaximizeWindow(const char* a_WindowName, bool a_NewState);
		static void MaximizeWindow(GLuint a_WindowIndex, bool a_NewState);

		//gets and sets for window name and index
		static const char* GetWindowName(GLuint a_WindowIndex);
		static GLuint GetWindowIndex(const char*  a_WindowName);

		static void SetWindowName(const char* a_WindowName, const char* a_NewName);
		static void SetWindowName(GLuint a_WindowIndex, const char* a_NewName);

		//gets and sets window is in focus(Linux only?)
		static bool GetWindowIsInFocus(const char* a_WindowName);
		static bool GetWindowIsInFocus(GLuint a_WindowIndex);
		static void FocusWindow(const char* a_WindowName, bool a_NewState);
		static void FocusWindow(GLuint a_WindowIndex, bool a_NewState);

		//gets and sets for restoring the window
		static void RestoreWindow(const char* a_WindowName);
		static void RestoreWindow(GLuint a_WindowIndex);

		//get window obscurity. I feel like this is completely useless
		//static bool GetWindowIsObscured(const char* a_WindowName);
		//static bool GetWindowIsObscured(GLuint a_WindowIndex);

		//enable vertical sync on selected window
		static void SetWindowSwapInterval(const char* a_WindowName, GLint a_EnableSync);
		static void SetWindowSwapInterval(GLuint a_WindowIndex, GLint a_EnableSync);
		
		//initialize the window manager
		static void Initialize();

		//ask the window to poll for window events
		static void PollForEvents();

		//remove a window from the manager
		static void RemoveWindow(F_W* a_Window);

		//set callbacks for the selected window
		static void SetWindowOnKeyEvent(const char* a_WindowName, OnKeyEvent a_OnKeyEvent);
		static void SetWindowOnKeyEvent(GLuint a_WindowIndex, OnKeyEvent a_OnKeyEvent);

		static void SetWindowOnMouseButtonEvent(const char* a_WindowName, OnMouseButtonEvent a_OnMouseButtonEvent);
		static void SetWindowOnMouseButtonEvent(GLuint a_WindowIndex, OnMouseButtonEvent a_OnMouseButtonEvent);

		static void SetWindowOnMouseWheelEvent(const char* a_WindowName, OnMouseWheelEvent a_OnMouseWheelEvent);
		static void SetWindowOnMouseWheelEvent(GLuint a_WindowIndex, OnMouseWheelEvent a_OnMouseWheelEvent);

		static void SetWindowOnDestroyed(const char* a_WindowName, OnDestroyed a_OnDestroyed);
		static void SetWindowOnDestroyed(GLuint a_WindowIndex, OnDestroyed a_OnDestroyed);

		static void SetWindowOnMaximized(const char* a_WindowName, OnMaximized a_OnMaximized);
		static void SetWindowOnMaximized(GLuint a_WindowIndex, OnMaximized a_OnMaximized);

		static void SetWindowOnMinimized(const char* a_WindowName, OnMinimized a_OnMiniimzed);
		static void SetWindowOnMinimized(GLuint a_WindowIndex, OnMinimized a_OnMiniimzed);

		static void SetWindowOnRestored(const char* a_WindowName, OnRestored a_OnRestored);
		static void SetWindowOnRestored(GLuint a_WindowIndex, OnRestored a_OnRestored);

		static void SetWindowOnFocus(const char* a_WindowName, OnFocus a_OnFocus);
		static void SetWindowOnFocus(GLuint a_WindowIndex, OnFocus a_OnFocus);

		static void SetWindowOnMoved(const char* a_WindowName, OnMoved a_OnMoved);
		static void SetWindowOnMoved(GLuint a_WindowIndex, OnMoved a_OnMoved);

		static void SetWindowOnResize(const char* a_WindowName, OnResize a_OnResize);
		static void SetWindowOnResize(GLuint a_WindowIndex, OnResize a_OnResize);

		static void SetWindowOnMouseMove(const char* a_WindowName, OnMouseMove a_OnMouseMove);
		static void SetWindowOnMouseMove(GLuint a_WindowIndex, OnMouseMove a_OnMouseMove);

	private:

		//get a static reference to the window manager
		static F_WM* GetInstance();

		std::vector<F_W*> m_Windows;
		static F_WM* m_Instance;

		GLuint m_ScreenResolution[2];
		GLuint m_ScreenMousePosition[2];

#if defined(CURRENT_OS_WINDOWS)
		LRESULT CALLBACK WindowProcedure(HWND a_WindowHandle, GLuint a_Message, WPARAM a_WordParam, LPARAM a_LongParam);
	
		static LRESULT CALLBACK StaticWindowProcedure(HWND a_WindowHandle, UINT a_Message, WPARAM a_WordParam, LPARAM a_LongParam);

		static F_W* GetWindowByHandle(HWND a_WindowHandle);

		static void Windows_PollForEvents();
		static void Windows_Initialize();
		static void Windows_Shutdown();
		static void Windows_SetMousePositionInScreen(GLuint a_X, GLuint a_Y);

		static void CreateTerminal();

		MSG m_Message;
		HDC m_DeviceContextHandle;
#endif

#if defined(CURRENT_OS_LINUX)
		static F_W* GetWindowByHandle(Window a_WindowHandle);
		static F_W* GetWindowByEvent(XEvent a_Event);

		static void Linux_Initialize();
		static void Linux_Shutdown();

		static void Linux_PollForEvents();
		static void Linux_SetMousePositionInScreen(GLuint a_X, GLuint a_Y);
		static Display* GetDisplay();

		Display* m_Display;
		XEvent m_Event;
#endif
};
#endif 
