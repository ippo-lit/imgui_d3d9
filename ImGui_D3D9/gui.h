#pragma once
#include <d3d9.h>

namespace gui {
	//constant window size
	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 500;

	extern bool exit_flag;

	//winapi window vars
	extern HWND window;
	extern WNDCLASSEXA windowClass;

	//points for window movement
	extern POINTS position;

	//direct x state vars
	extern PDIRECT3D9 d3d;
	extern LPDIRECT3DDEVICE9 device;
	extern D3DPRESENT_PARAMETERS presentParameters;

	//handle window creation & destruction
	void CreateHWindow(
		const char* windowName,
		const char* className) noexcept;
	void DestroyHWindow() noexcept;

	//handle device creation & destruction
	bool CreateDevice() noexcept;
	void ResetDevice() noexcept;
	void DestroyDevice() noexcept;

	//handle ImGui creation & destruction
	void CreateImGui() noexcept;
	void DestroyImGui() noexcept;

	void BeginRender() noexcept;
	void EndRender() noexcept;
	void Render() noexcept;
}

