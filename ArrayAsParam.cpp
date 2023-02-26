#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void fun(int A[], int n)
{
    // we cant use any foreach loop on pointer but we can use for loop
    return;
}

int main()
{

    int A[] = {2, 3, 566, 4};
    int n = 5;

    for (int x : A)
    {
        cout << x << endl;
    }
    return 0;
}