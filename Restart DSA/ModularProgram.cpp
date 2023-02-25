#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int area(int l, int b) {
    return l * b;
}

int main() {
    int length = 0, breadth = 0;

    printf("Enter Length and Breath: ");

    cin>>length>>breadth;

    int c = area(length, breadth);

    cout<<c;

    return 0;
}