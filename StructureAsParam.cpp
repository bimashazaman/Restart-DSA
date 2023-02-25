#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

struct Rec {
    int len;
    int Ber;
};


void fun(struct Rec r2) {
     cout<<r2.len;
}

int main() {

/* Creating a struct called r1 with two fields, len and Ber. */
    struct Rec r1 = {1,3};

    fun(r1);

    return 0;
}