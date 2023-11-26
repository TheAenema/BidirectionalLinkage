// DLL Code
#include <Windows.h>
#include <iostream>

// Macros
#define log(fmt,...) printf(fmt "\n",__VA_ARGS__);

// Import From EXE
extern "C" __declspec(dllimport) void SomeProgramFunction();

// Entrypoint
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) 
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        log("X30 Library Loaded.");
        // SomeProgramFunction(); // Not Works
    }
    return TRUE;
}

// Export From DLL
extern "C" __declspec(dllexport) void SomeLibraryFunction()
{
    log("X30 Library SomeLibraryFunction Called.");
    SomeProgramFunction(); // Works
}