#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// dsa of doubly circular linked list

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = first;
    first->next = first;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        first->prev = t;
        last = t;
    }
}

void display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != first);
}

// recursive

void Rdisplay(struct Node *p)
{
    static int flag = 0;
    if (p != first || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        Rdisplay(p->next);
    }
    flag = 0;
}

int count(struct Node *p)
{
    int l = 0;
    do
    {
        l++;
        p = p->next;
    } while (p != first);
    return l;
}

// insert a node at a given position

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
        if (first == NULL)
        {
            first = t;
            first->next = first;
        }
        else
        {
            while (p->next != first)
                p = p->next;
            p->next = t;
            t->next = first;
            first->prev = t;
            t->prev = p;
            first = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}

// delete a node at a given position

int deleteNode(struct Node *p, int index)
{
    struct Node *q;
    int x, i;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        while (p->next != first)
            p = p->next;
        x = first->data;
        if (first == p)
        {
            delete first;
            first = NULL;
        }
        else
        {
            p->next = first->next;
            delete first;
            first = p->next;
            first->prev = p;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        q->next->prev = p;
        x = q->data;
        delete q;
    }
    return x;
}

void reverse(struct Node *p)
{
    struct Node *temp;
    do
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p && p->next == first)
            first = p;
    } while (p != first);
}

void reverse2(struct Node *p)
{
    struct Node *temp;
    do
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p && p->next == first)
            first = p;
    } while (p != first);
}

// more

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);
    cout << endl;
    Rdisplay(first);
    cout << endl;
    cout << count(first) << endl;
    insert(first, 0, 5);
    display(first);
    cout << endl;
    cout << deleteNode(first, 1) << endl;
    display(first);
    cout << endl;
    return 0;
}
