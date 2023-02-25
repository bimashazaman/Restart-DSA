#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

int main() {

    int a = 100;

    /* Creating a reference to a. */
    int &r = a;

    cout<<r<<endl;

    return 0;
}