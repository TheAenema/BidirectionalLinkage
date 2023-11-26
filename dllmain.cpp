// DLL Code
#include <Windows.h>
#include <iostream>

// Macros
#define log(fmt,...) printf(fmt "\n",__VA_ARGS__);

// Import From EXE

typedef void(*SomeProgramFunctionFunc)(void);
SomeProgramFunctionFunc SomeProgramFunction = nullptr;

// Entrypoint
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) 
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        log("X30 Library Loaded.");
        HMODULE lib = LoadLibrary(L"X30Library");
        if (!lib) return EXIT_FAILURE;
        SomeProgramFunction = (SomeProgramFunctionFunc)GetProcAddress(lib, "SomeLibraryFunction");
        if (!SomeProgramFunction) return EXIT_FAILURE;
        SomeProgramFunction();
    }
    return TRUE;
}

// Export From DLL
extern "C" __declspec(dllexport) void SomeLibraryFunction()
{
    log("X30 Library SomeLibraryFunction Called.");
    if (!SomeProgramFunction) SomeProgramFunction();
}