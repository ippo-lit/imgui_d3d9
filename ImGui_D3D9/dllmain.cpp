// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "../ImGui_D3D9/Bot/UI/gui.h"

#include <thread>

int __stdcall GuiMain( //for .exe application wWinMain
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow) {
	//create gui
	gui::CreateHWindow("Menu", "Menu Class");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::exit) {

		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	//destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}

BOOL WINAPI DllMain(const HINSTANCE hinstDLL, const DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		const HANDLE hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)GuiMain, hinstDLL, 0, nullptr);
		if (hThread != INVALID_HANDLE_VALUE && hThread != nullptr)
			CloseHandle(hThread);
	}

	return TRUE;
}

