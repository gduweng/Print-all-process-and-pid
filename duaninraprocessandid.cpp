#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <psapi.h>
#include <wtsapi32.h>
#include <list>
#include <algorithm>
#include <string>
#include <cctype>
#include <sstream>
#include <iostream>
#define MAX_PATH1 1024
using namespace std;

void inra(DWORD a) {
	HANDLE moprocess;
	moprocess = OpenProcess(
		PROCESS_ALL_ACCESS | PROCESS_QUERY_INFORMATION | PROCESS_QUERY_LIMITED_INFORMATION,
		FALSE,
		a
	);
	if (moprocess == NULL) {
		cout << "fail " << GetLastError() << endl;
	}
	else
	{
		cout << "thanh cong mo process" << endl;

		TCHAR tenpro[1024];
		DWORD newfuntions;
		newfuntions = GetProcessImageFileNameW(
			moprocess,
			tenpro,
			sizeof(tenpro) / sizeof(*tenpro)
		);
		if (newfuntions == 0)
			cout << "that bai get process image name  " << GetLastError() << endl;
		wcout << tenpro << "------" << a << endl;
	}
}
int main() {
	BOOL enumid;
	system("pause");


	DWORD mangchuagiatri[1024];
	//DWORD cb;
	DWORD lpcbNeeded;
	enumid = EnumProcesses(
		mangchuagiatri,
		sizeof(mangchuagiatri),
		&lpcbNeeded);
	int i = lpcbNeeded / sizeof(DWORD);
	for (int a = 0; a < i; a++)
		if (mangchuagiatri[a] != 0) {
			
			inra(mangchuagiatri[a]);
		}

	system("pause");
	


	return 0;
}
