#include <tchar.h>
#include <windows.h>
#include <iostream>

int Product(int[], int[], const int);

const int n = 100000000; //100000000;  100,000,000
static int x[n];
static int y[n];


using namespace std;

int main()
{
	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0, i = 0;
	int sum;
	int j;
	for (j = 0; j < n; j++){
		x[j] = 2;
		y[j] = 3;
	}		
	// Start timing the code.
	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		// Code segment is being timed.
		sum = Product(x, y, n);

		// Finish timing the code.
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);

		cout << "Start Value: {0}" << ctr1 << endl;
		cout << "End Value: {0}" << ctr2 << endl;

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

		//old version code: Console::WriteLine(S"QueryPerformanceCounter minimum resolution: 1/{0} Seconds.", freq.ToString());
		cout << "QueryPerformanceCounter minimum resolution: 1/{0} Seconds." << freq << endl;
		cout << n << " Increment time: {0} seconds." << (ctr2 - ctr1) * 1.0 / freq << endl; // changed size to n


		cout << "End Value - Start Value = " << ctr2 - ctr1 << endl;

	}
	else
	{
		DWORD dwError = GetLastError();
		//old version code:  Console::WriteLine(S"Error value = {0}", dwError.ToString());
		cout << "Error value = {0}" << dwError << endl;
	}

	// Make the console window wait.
	system("PAUSE");

	return 0;
}