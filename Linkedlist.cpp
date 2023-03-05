#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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

// circular

void createCircular(int A[], int n)
{
    int i;
    struct Node *temp, *last;

    first = new Node;
    first->data = A[0];
    first->next = first;
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void displayCircular(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != first);
}

void insertCircular(struct Node *p, int index, int x)
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
        if (first == NULL)
        {
            first = t;
            first->next = first;
        }
        else
        {
            while (p->next != first)
            {
                p = p->next;
            }
            p->next = t;
            t->next = first;
            first = t;
        }
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

void deleteCircular(struct Node *p, int index)
{
    struct Node *q;
    int i;

    /* Checking if the index is valid or not. */
    if (index < 0 || index > count(p))
    {
        return;
    }

    /* Deleting the node at the beginning of the linked list. */
    if (index == 1)
    {
        while (p->next != first)
        {
            p = p->next;
        }
        if (p == first)
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
        /* Moving the pointer to the node before the index. */
        for (i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
    }
}

void insertFirst(struct Node *p, int x)
{
    struct Node *t;
    t = new Node;
    t->data = x;
    t->next = first;
    first = t;
}

void insertAfter(struct Node *p, int index, int x)
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

    /* Moving the pointer to the node before the index. */
    for (i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    /* Inserting a node after a given node. */
    t->next = p->next;
    p->next = t;
}

void insertLast(struct Node *p, int x)
{
    struct Node *t;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}

void insertSorted(struct Node *p, int x)
{

    struct Node *t, *q = NULL;

    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int deleteNode(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p))
    {
        return -1;
    } // invalid index

    if (index == 1)
    {
        q = first;           // q is pointing to the first node
        x = first->data;     // x is storing the data of the first node
        first = first->next; // first is pointing to the second node
        delete q;            // deleting the first node
        return x;            // returning the data of the deleted node
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;       // q is pointing to the previous node
            p = p->next; // p is pointing to the current node
        }
        q->next = p->next; // q is pointing to the next node of p
        x = p->data;       // x is storing the data of the current node
        delete p;          // deleting the current node
        return x;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536; // minimum value of int data type

    while (p != NULL) // traversing the linked list
    {
        if (p->data < x) // if the data of the current node is less than the previous node
        {
            return 0; // the linked list is not sorted
        }
        x = p->data; // x is storing the data of the current node
        p = p->next; // p is pointing to the next node of the current node
    }
    return 1;
}

void removeDuplicates(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = new int[count(p)];

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concat(struct Node *p, struct Node *q)
{
    third = p;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    if (q)
    {
        last->next = q;
    }
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    // menu driven program
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);

    display(first);
    cout << endl;
    cout << count(first) << endl;
    cout << sum(first) << endl;
    cout << max(first) << endl;
    cout << endl;

    struct Node *temp;
    temp = Lsearch(first, 10);

    if (temp)
    {
        cout << "Key is found: " << temp->data << endl;
    }
    else
    {
        cout << "Key is not found" << endl;
    }

    insert(first, 2, 20);

    display(first);
    cout << endl;

    insertLast(first, 25);

    display(first);
    cout << endl;

    insertSorted(first, 2);

    display(first);

    cout << endl;

    return 0;
}