#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

/**
 * A Rec is a struct with two fields, len and ber, both of which are integers.
 * @property {int} len - the length of the record
 * @property {int} ber - The BER of the packet.
 */
struct Rec {
        int len;
        int ber;
    };


int main(){

   /* Creating a struct called r with two fields, len and ber, both of which are integers. */
   Rec r = {10,60};


   /* Creating a pointer to the struct r. */
    Rec *p = &r;

  /* Allocating memory for the struct. */
    p = (struct Rec *)malloc(sizeof(struct Rec));

   /* Assigning the values 14 and 67 to the fields len and ber respectively. */
    p->len =14;
    p->ber =67;

    cout<<p->len;

  

    return 0;
}