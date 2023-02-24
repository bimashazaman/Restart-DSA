#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 



int main () {

    int a = 10; // consumes 4 bytes

    int *p;  //declaration of a pointer

    p = &a; //assigning address of a, here in p we dont need to add start we only add that while declaring , defererancing

    printf("%d", *p); // dereferencing here by *p

    return 0;
}


