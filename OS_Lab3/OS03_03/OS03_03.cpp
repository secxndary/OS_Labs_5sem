#include <iostream>
#include <Windows.h>
#include "TlHelp32.h"
#include <iomanip>
using namespace std;

int main()
{
	DWORD pid = GetCurrentProcessId();
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 peProcessEntry;
	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	wcout << L"Current PID: " << pid << endl;

	try
	{
		if (!Process32First(snap, &peProcessEntry))
			throw L"Process32First";
		do
		{
			if (peProcessEntry.th32ProcessID == pid)
				wcout << "  ! CURRENTLY RUNNING PROCESS !\n";
			wcout << L"Name\t\t" << peProcessEntry.szExeFile << endl << L"PID\t\t" << peProcessEntry.th32ProcessID;
			wcout << L"\nParent PID\t" << peProcessEntry.th32ParentProcessID << "\n";
			wcout << L"-----------------------------------\n";

		} while (Process32Next(snap, &peProcessEntry));
	}
	catch (char* errMessage)
	{
		wcout << L"[ERROR] " << errMessage;
	}

	system("pause");
	return 0;
}
