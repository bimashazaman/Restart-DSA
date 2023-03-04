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

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    struct Node *p = first;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// recursive
void Rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        Rdisplay(p->next);
    }
}

int count(struct Node *p)
{
    int l = 0;
    while (p != NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if (p != NULL)
    {
        return Rcount(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node *p)
{
    if (p != NULL)
    {
        return Rsum(p->next) + p->data;
    }
    else
    {
        return 0;
    }
}

int max(struct Node *p)
{
    int max = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    x = Rmax(p->next);
    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

struct Node *Lsearch(struct Node *p, int key)
{
    struct Node *temp = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            temp->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        temp = p;
        p = p->next;
    }
    return NULL;
}

struct Node *Rsearch(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p;
    }
    return Rsearch(p->next, key);
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    /* Checking if the index is valid or not. */
    if (index < 0 || index > count(p))
    {
        return;
    }

    /* Creating a new node and assigning the value of x to the data of the node. */
    t = new Node;
    t->data = x;

    /* Inserting the node at the beginning of the linked list. */
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        /* Moving the pointer to the node before the index. */
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        /* Inserting a node after a given node. */
        t->next = p->next;
        p->next = t;
    }
}
int main()
{

    int A[] = {3, 34, 4, 2, 211, 1};

    create(A, 6);
    display(first);

    return 0;
}