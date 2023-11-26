// EXE Code
#include <Windows.h>
#include <iostream>

// Macros
#define log(fmt,...) printf(fmt "\n",__VA_ARGS__);

// Entrypoint
int main() 
{
	log("Program : Executing Library...");
	HMODULE lib = LoadLibrary(L"X30Library");
	if (!lib) return EXIT_FAILURE;
	typedef void(*SomeLibraryFunctionFunc)(void);
	auto SomeLibraryFunction = (SomeLibraryFunctionFunc)GetProcAddress(lib, "SomeLibraryFunction");
	if (!SomeLibraryFunction) return EXIT_FAILURE;
	SomeLibraryFunction();
	log("Program : END");
	system("pause");
	return EXIT_SUCCESS;
}

// Export From EXE
extern "C" __declspec(dllexport) void SomeProgramFunction()
{
	log("X30 Program SomeProgramFunction Called.");
}