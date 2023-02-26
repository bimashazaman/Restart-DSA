#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int length = 0, breath = 0;

    printf("Enter Length and Breath: ");

    cin >> length >> breath;

    int area = length * breath;

    cout << area;

    return 0;
}