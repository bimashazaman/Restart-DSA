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

   /* Re-Assigning values to the variables of the struct. */
    r1.len = 100;
    r1.bredth = 200;

  /* Printing the value of len and bredth of the struct r1. */
    cout<<r1.len<<endl;
    cout<<r1.bredth<<endl;
    

    // printf("%lu", sizeof(r1)); 
    return 0;
};