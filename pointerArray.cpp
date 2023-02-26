#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

    int A[5] = {1, 34, 45, 56, 4};
    int *p;

    p = A; // dont need to use & for getting the address of A[5] because A is an address of the emems in the array

    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;

    return 0;
};