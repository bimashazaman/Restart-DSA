#include <stdio.h>
#include<iostream>

using namespace std;


struct Rec {
    int len; // 4 bytes
    int bredth; // 4 bytes
    char x; // allocating 4 bytes but using 1 bytes
}; // Defination of our struct it doesnt consume memory 


int main() {

    /* Creating a variable of type struct Rec. */
    struct Rec r1 = {10,5};

    printf("%lu", sizeof(r1)); //8 bytes
    return 0;
};