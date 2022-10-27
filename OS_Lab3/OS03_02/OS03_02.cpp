#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	cout << "====================  OS03_02  ====================\n\n";

	LPCWSTR OS03_02_1 = L"C:\\Users\\valda\\source\\repos\\semester#5\\ОСИ\\OS_Lab3\\x64\\Debug\\OS03_02_1.exe";
	LPCWSTR OS03_02_2 = L"C:\\Users\\valda\\source\\repos\\semester#5\\ОСИ\\OS_Lab3\\x64\\Debug\\OS03_02_2.exe";
	STARTUPINFO si;	
	PROCESS_INFORMATION pi;	
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);


	if (CreateProcess(OS03_02_1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
		cout << "[OK] Process OS03_02_1 was created.\n";
	else cout << "[ERROR] Process OS03_02_1 was not created.\n";


	if (CreateProcess(OS03_02_2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
		cout << "[OK] Process OS03_02_2 was created.\n\n";
	else cout << "[ERROR] Process OS03_02_2 was not created.\n\n";


	for (short i = 1; i <= 100; ++i)
	{
		cout << i << ". PID = " << GetCurrentProcessId() << "\n";
		Sleep(1000);
	}


	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}

// CMD: tasklist /FI "IMAGENAME eq OS03_02*"