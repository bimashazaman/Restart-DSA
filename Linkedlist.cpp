#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *temp, *last;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
}

int main()
{

    int A[] = {3, 34, 4, 2, 211, 1};

    create(A, 6);

    return 0;
}