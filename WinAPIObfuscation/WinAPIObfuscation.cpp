#include "pch.h"
#include <iostream>
#include "hash_work.h"

using namespace std;
int main()
{
	DWORD pointre;
	HANDLE hFile = hash_CreateFileA("log.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile) {
		std::cout << "Error open file!\n";
		while (1);
	}

	// TODO: VirtualProtect. Fix this bad code.
	//const int Addr1 = 0x70000000;
	//char st[256] = "qweqwe";
	//int NumberOfBytes1 = sizeof(st);
	//bool vp = hash_VirtualProtect((LPVOID)Addr1, NumberOfBytes1, PAGE_EXECUTE_READWRITE, 0);
	// -----------------------

	// VirtualAlloc/VirtualFree
	LPVOID p = NULL;
	p = hash_VirtualAlloc(NULL, 4000, MEM_RESERVE, PAGE_READWRITE);
	if (p != NULL)
	{
		cout << "OK Alloc " << endl;
		if (hash_VirtualFree(p, 0, MEM_RELEASE))
			cout << "Ok Free" << endl;
		else
			cout << "Not Free" << endl;
	}
	else
		cout << "Error Alloc " << endl;
	// -----------------------

	system("pause");

	return 1;
}