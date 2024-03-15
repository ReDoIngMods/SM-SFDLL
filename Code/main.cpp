#include "Utils/Memory.hpp"

void process_attach()
{
	Memory::WriteMemory<std::uint16_t>(0x462F16, 0xEB29);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		process_attach();
		break;
	case DLL_PROCESS_DETACH:
		FreeLibrary(hModule);
		break;
	}

	return TRUE;
}