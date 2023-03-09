#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// Binary tree DSA

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create a new node
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a node
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return newNode(data);
    else
    {
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }
}

// Search a node
bool search(Node *node, int data)
{
    if (node == NULL)
        return false;
    else if (node->data == data)
        return true;
    else if (data <= node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}

// Find the minimum value
int findMin(Node *node)
{
    if (node == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    else if (node->left == NULL)
        return node->data;
    else
        return findMin(node->left);
}

// Find the maximum value
int findMax(Node *node)
{
    if (node == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    else if (node->right == NULL)
        return node->data;
    else
        return findMax(node->right);
}

// Find the height of the tree
int findHeight(Node *node)
{
    if (node == NULL)
        return -1;
    else
        return max(findHeight(node->left), findHeight(node->right)) + 1;
}

// Find the number of nodes
int findNumNodes(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return findNumNodes(node->left) + findNumNodes(node->right) + 1;
}

// Find the number of leaves
int findNumLeaves(Node *node)
{
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return findNumLeaves(node->left) + findNumLeaves(node->right);
}

// Find the number of internal nodes
int findNumInternalNodes(Node *node)
{
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    else
        return findNumInternalNodes(node->left) + findNumInternalNodes(node->right) + 1;
}

// Find the number of full nodes
int findNumFullNodes(Node *node)
{
    if (node == NULL)
        return 0;
    else if (node->left != NULL && node->right != NULL)
        return findNumFullNodes(node->left) + findNumFullNodes(node->right) + 1;
    else
        return findNumFullNodes(node->left) + findNumFullNodes(node->right);
}

// Find the number of half nodes
int findNumHalfNodes(Node *node)
{
    if (node == NULL)
        return 0;
    else if ((node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL))
        return findNumHalfNodes(node->left) + findNumHalfNodes(node->right) + 1;
    else
        return findNumHalfNodes(node->left) + findNumHalfNodes(node->right);
}

// Preorder traversal
void preorder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Inorder traversal
void inorder(Node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

// Postorder traversal
void postorder(Node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

// Level order traversal
void levelorder(Node *node)
{
    int h = findHeight(node);
    for (int i = 0; i <= h; i++)
        printGivenLevel(node, i);
}

// Print nodes at a given level
void printGivenLevel(Node *node, int level)
{
    if (node == NULL)
        return;
    if (level == 0)
        cout << node->data << " ";
    else if (level > 0)
    {
        printGivenLevel(node->left, level - 1);
        printGivenLevel(node->right, level - 1);
    }
}

// Delete a node

// Find the minimum value in a subtree
int findMin(Node *node)
{
    if (node == NULL)
    {
        cout << "Error: Tree is empty" << endl;
        return -1;
    }
    else if (node->left == NULL)
        return node->data;
    else
        return findMin(node->left);
}

// Find the height of a subtree
int findHeight(Node *node)
{
    if (node == NULL)
        return -1;
    else
        return max(findHeight(node->left), findHeight(node->right)) + 1;
}

// Find the number of nodes in a subtree
int findNumNodes(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return findNumNodes(node->left) + findNumNodes(node->right) + 1;
}
