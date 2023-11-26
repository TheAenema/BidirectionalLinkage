// EXE Code
#include <Windows.h>
#include <iostream>

// Macros
#define log(fmt,...) printf(fmt "\n",__VA_ARGS__);

// Import From DLL
extern "C" __declspec(dllimport) void SomeLibraryFunction();

// Entrypoint
int main() 
{
	log("Program : Executing Library...");
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