#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int fun(int n)
{
    static int x = 0;

    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }

    return 0;
}

int main()
{
    int x = 4;

    fun(x);
    return 0;
}