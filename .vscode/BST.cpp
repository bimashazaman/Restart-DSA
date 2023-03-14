#include <iostream>

using namespace std;

class Node
{
public:
    Node *lchild; // left child
    int data;     // data
    Node *rchild; // right child
};                // Node

class BST
{
private:
    Node *root; // root node

public:
    BST() { root = nullptr; }
    Node *getRoot() { return root; }
    void Insert(int key);
    void Inorder(Node *p);
    Node *Search(int key);
};

void BST::Insert(int key) // Insert a node in BST
{

    Node *t = root; // t is a pointer to root
    Node *p;        // p is a pointer to new node
    Node *r;        // r is a pointer to parent of t

    // root is empty
    if (root == nullptr)
    {
        p = new Node;        // create a new node
        p->data = key;       // set data
        p->lchild = nullptr; // set left child to null
        p->rchild = nullptr; // set right child to null
        root = p;            // set root to p
        return;              // exit
    }

    while (t != nullptr) // while t is not null
    {
        r = t;             // set r to t
        if (key < t->data) // if key is less than t's data
        {
            t = t->lchild; // set t to t's left child
        }
        else if (key > t->data) // if key is greater than t's data
        {
            t = t->rchild; // set t to t's right child
        }
        else
        {
            return; // exit
        }
    }

    // Now t points at NULL and r points at insert location
    p = new Node;        // create a new node
    p->data = key;       // set data
    p->lchild = nullptr; // set left child to null
    p->rchild = nullptr; // set right child to null

    if (key < r->data)
    {
        r->lchild = p; // set r's left child to p
    }
    else
    {
        r->rchild = p; // set r's right child to p
    }
}

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node *BST::Search(int key)
{
    Node *t = root;
    while (t != nullptr)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return nullptr;
}

int main()
{

    BST bst;

    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Search
    Node *temp = bst.Search(2);
    if (temp != nullptr)
    {
        cout << temp->data << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}