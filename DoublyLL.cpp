#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// dsa of doubly linked list

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;            // t is a temporary node
    first = new Node;                 // create a new node
    first->data = A[0];               // assign data to the new node
    first->prev = first->next = NULL; // the next pointer of the new node is NULL
    last = first;                     // assign the new node to the last node

    for (i = 1; i < n; i++)
    {
        t = new Node;         // create a new node
        t->data = A[i];       // assign data to the new node
        t->next = last->next; // the next pointer of the new node is NULL
        t->prev = last;       // the next pointer of the last node is the new node
        last->next = t;       // assign the new node to the last node
        last = t;             // assign the new node to the last node
    }
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
        return Rcount(p->next) + 1;
    else
        return 0;
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
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

// recursive
void Rinsert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > count(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        Rinsert(p->next, index - 1, x);
    }
}

// search
struct Node *search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// recursive
struct Node *Rsearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return Rsearch(p->next, key);
}

// delete
int deleteNode(struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

// recursive
int Rdelete(struct Node *p, int index)
{
    int x = -1;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        x = Rdelete(p->next, index - 1);
    }
    return x;
}

// reverse
void reverse(struct Node *p)
{
    struct Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

// recursive
void Rreverse(struct Node *p)
{
    if (p != NULL)
    {
        Rreverse(p->next);
        cout << p->data << " ";
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    cout << "Sum is " << sum(first) << endl;
    cout << "Rsum is " << Rsum(first) << endl;
    return 0;
}

// Path: DoublyLL.cpp
