#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun(n - 1);
        fun(n - 1);
    }
}

int main()
{
    fun(3);
    return 0;
}