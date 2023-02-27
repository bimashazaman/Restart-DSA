#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

/* Declaring the functions A and B. */
void B(int n);
void A(int n);

void A(int n)
{
    if (n > 0)
    {
        cout << n;
        B(n - 1);
    }
}

void B(int n)
{
    if (n > 0)
    {
        cout << n;
        A(n - 1);
    }
}

int main()
{
    A(3);
    return 0;
}