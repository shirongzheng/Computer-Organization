// Factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int factorial (int N){
    if (N==1)
        return 1;
    return (N*factorial(N-1));
}

void main(){
    int N_fact = factorial(5);
}

