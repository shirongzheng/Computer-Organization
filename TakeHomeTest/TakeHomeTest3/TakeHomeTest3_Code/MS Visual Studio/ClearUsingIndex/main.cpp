#include "stdafx.h"
#include <tchar.h>
#include <windows.h>
#include <iostream>
using namespace std;
void ClearUsingIndex(int[], int);
const int n = 100000000;
static int arr[n];

int main()
{
	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0, i = 0;
	int j;
	for (j = 0; j < n; j++)
		arr[j] = j;

	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		ClearUsingIndex(arr, n);
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);

		cout << "Start Value: " << ctr1 << endl;
		cout << "End Value: " << ctr2 << endl;

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		cout << "QueryPerformanceCounter minimum resolution: 1/Seconds." << freq << endl;
		cout << n << " Increment time: seconds." << (ctr2 - ctr1) * 1.0 / freq << endl; // changed size to n


		cout << "End Value - Start Value = " << ctr2 - ctr1 << endl;

	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error value = {0}" << dwError << endl;
	}

	system("PAUSE");

	return 0;
}