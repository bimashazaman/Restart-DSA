#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

// so we will call by adddress now
void func1(int *x, int *y) {
  /* Swapping the values of x and y. */
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};

int main() {
    int x = 10;
    int y = 20;

   func1(&x, &y);

    cout<<x;
    return 0;
}