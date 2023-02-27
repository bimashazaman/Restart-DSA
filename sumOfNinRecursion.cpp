#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sum(n - 1) + n;
    }
}
int loopSum(int n)
{
    int s = 0, i;
    /* Adding all the numbers from 0 to n. */
    for (i = 0; i <= n; i++)
    {
        s = s + i;
    }
    return s;
} // better space complexity

int main()
{
    int r = 5;

    int result = loopSum(r);

    cout << result;
    return 0;
}