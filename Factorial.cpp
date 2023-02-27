#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return sum(n - 1) * n;
    }
}

int main()
{
    int r = 4;

    int result = sum(r);

    cout << result;
    return 0;
}