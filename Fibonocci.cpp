#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int fib(int n)
{
    int i = 0, t0 = 0, t1 = 1, s = 0;

    if (n <= 1)
    {
        return n;
    }

    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

int rfib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return rfib(n - 2) + rfib(n - 1);
}
// testing new
int main()
{

    cout << rfib(10);
    return 0;
}