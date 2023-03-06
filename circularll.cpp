#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// dsa circular linked list

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = first;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
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

// insert a node in a circular linked list

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
        p->next = t;
    }
}

// delete a node in a circular linked list
int deleteNode(struct Node *p, int index)
{
    struct Node *q;
    int i, x;

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
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

// check if a linked list is circular or not
void isCircular(struct Node *f)
{
    struct Node *p = f;
    do
    {
        p = p->next;
    } while (p != f && p != NULL);
    if (p == f)
        cout << "Circular" << endl;
    else
        cout << "Not Circular" << endl;
}

// check if a linked list is circular or not
void isCircular2(struct Node *f)
{
    struct Node *p = f;
    while (p != NULL)
    {
        p = p->next;
        if (p == f)
        {
            cout << "Circular" << endl;
            return;
        }
    }
    cout << "Not Circular" << endl;
}

// doubly circular linked list

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display(first);
    cout << endl;
    Rdisplay(first);
    cout << endl;
    cout << count(first) << endl;
    return 0;
}
