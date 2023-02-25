#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

int main() {
   /* Allocating memory for 5 integers. */
    int *p;
    p = (int *)malloc(5*sizeof(int));

    p[1] = 10;
    p[2] = 1430;
    p[3] = 120;
    p[4] = 130;
    p[5] = 120;

/* Printing the values of the array. */
     for(int i= 0; i<5; i++)
        cout<<p[i]<<endl;

       /* Deleting the array. */
        free(p);
   return 0;
}