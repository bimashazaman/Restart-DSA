#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int *p, *q;

    p = new int[5];
    q = new int[10];

    p[0] = 21;
    p[1] = 13;
    p[2] = 11;
    p[3] = 178;
    p[4] = 143;

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    free(p);

    p = q;

    q = NULL;

    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << endl;
    }
    cout << *p;

    return 0;
}