#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

int func1(int a, int b) {
    return a + b;
}

int main() {
    int x = 10;
    int y = 20;
    int z = func1(x, y);

    cout << z;
    return 0;
}