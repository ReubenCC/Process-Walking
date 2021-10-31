#include <Windows.h>
#include <tlhelp32.h>
#include <iostream>
using namespace std;
int main() {
	PROCESSENTRY32W ptr;
	ptr.dwSize = sizeof(PROCESSENTRY32);
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	cout << Process32First(snap, &ptr) << endl;
	wcout << ptr.szExeFile;
	cout << ": " << ptr.th32ProcessID << endl;
	while (Process32Next(snap, &ptr)) {
		wcout << ptr.szExeFile;
		cout << ": " << ptr.th32ProcessID;
		cout << ": " << ptr.th32ParentProcessID << endl;
	}
	return 0;
}
