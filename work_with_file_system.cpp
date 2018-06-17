#include <iostream>
#include <cstdio>
#include "Windows.h"

using namespace std;
int input = 1;
LPCTSTR lpFileName = TEXT("C:\\..path to the file..\\MyFile.txt");

int main()
{
	cout << "1 - attribute setting ---> read" << endl;
	cout << "2 - attribute setting ---> write" << endl;
	cout << "3 - devices on disk" << endl;
	cout << endl;

	while (input != 0)
	{
		cin >> input;
		switch (input)
		{
		case 1:
			SetFileAttributes(lpFileName, FILE_ATTRIBUTE_READONLY);
			cout << "attribute : " << GetFileAttributes(lpFileName) << endl;
			cout << endl;
			cout << "next action" << endl;
			break;
		case 2:
			SetFileAttributes(lpFileName, FILE_ATTRIBUTE_NORMAL);
			cout << "attribute : " << GetFileAttributes(lpFileName) << endl;
			cout << endl;
			cout << "next action" << endl;
			break;
		case 3:
			cout << "devices on disk : " << endl;
			DWORD driv = GetLogicalDrives();
			char temp[4];
			for (int dc = 0; dc < 6; dc++)
			{
				if (driv & (3 << dc))
					cout << dc << " ";
				{
					temp[1] = 0;
					temp[0] = 'A' + dc;
					if (temp[0] != 'A') cout << "found disk:" << temp << endl;
				}
			}
			cout << endl;
			cout << "next action" << endl;
			break;
		}
	}
	system("pause");
}
