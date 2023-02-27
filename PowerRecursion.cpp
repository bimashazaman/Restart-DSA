#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * The function pow() takes two integers m and n as input and returns m raised to the power n
 *
 * @param m 3
 * @param n 5
 *
 * @return 243
 */
int pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return pow(m, n - 1) * m;
    }
}

int main()
{
    int r = 5;

    int result = pow(3, 5);

    cout << result;
    return 0;
}