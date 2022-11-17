#include <iostream>
#include <cstdlib>
#include "Windows.h"
using namespace std;


int main()
{
	HANDLE processHandle = GetCurrentProcess();
	HANDLE threadHandle = GetCurrentThread();
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	DWORD processPriority = GetPriorityClass(processHandle);

	cout << "------------------------------------------\n\n";
	cout << "Current PID:       " << pid << "\n";

	switch (processPriority) 
	{
	case IDLE_PRIORITY_CLASS:			cout << "Process Priority:  IDLE_PRIORITY_CLASS\n";			break;
	case BELOW_NORMAL_PRIORITY_CLASS:	cout << "Process Priority:  BELOW_NORMAL_PRIORITY_CLASS\n";	break;
	case NORMAL_PRIORITY_CLASS:			cout << "Process Priority:  NORMAL_PRIORITY_CLASS\n";		break;
	case ABOVE_NORMAL_PRIORITY_CLASS:	cout << "Process Priority:  ABOVE_NORMAL_PRIORITY_CLASS\n";	break;
	case HIGH_PRIORITY_CLASS:			cout << "Process Priority:  HIGH_PRIORITY_CLASS\n";			break;
	case REALTIME_PRIORITY_CLASS:		cout << "Process Priority:  REALTIME_PRIORITY_CLASS\n";		break;
	default:							cout << "[ERROR] Unknown process priority.\n";				break;
	}


	cout << "\n------------------------------------------\n\n";

	system("pause");
}