#include "pch.h"

#include "gui.h"

int WINAPI wWinMain(
	_In_ HINSTANCE instance,
	_In_opt_ HINSTANCE previousInstance,
	_In_ PWSTR arguments,
	_In_ int commandShow) {
	//create gui
	gui::CreateHWindow("Menu", "Menu Class");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::exit_flag) {

		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	//destroy gui
	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

#ifdef _WINDLL
	ExitThread(0);
#endif

	return EXIT_SUCCESS;
}

#ifdef _WINDLL
BOOL WINAPI DllMain(const HINSTANCE hinstDLL, const DWORD fdwReason, LPVOID lpReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		const HANDLE hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)wWinMain, hinstDLL, 0, nullptr);
		if (hThread != INVALID_HANDLE_VALUE && hThread != nullptr)
			CloseHandle(hThread);
	}

	return TRUE;
}
#endif

