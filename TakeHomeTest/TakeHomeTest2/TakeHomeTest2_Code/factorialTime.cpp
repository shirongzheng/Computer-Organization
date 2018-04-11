#include <iostream>
#include <string>
#include <ctime>
using namespace std;


int factorial (int N)
{
    if (N==1)
        return 1;
    return (N*factorial(N-1));
}


int main()

{
    
    int startTime = clock();
    int Nfactorial = factorial(10000);
    int stopTime = clock();

    cout << "factorial(10000) " << "time: " << (stopTime-startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
    
    
}
