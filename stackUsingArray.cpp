#include <iostream>
using namespace std;

class Stack
{
    /* Declaring the variables that will be used in the class. */
private:
    int size;
    int top;
    int *S;

public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int stackTop();
};

/**
 * The constructor initializes the stack with a size and sets the top to -1.
 *
 * @param size The size of the stack.
 */
Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}

/**
 * The destructor frees the memory allocated for the stack
 */
Stack::~Stack()
{
    delete[] S;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top++;
        S[top] = x;
    }
}

int Stack::pop()
{
    int x = 1;
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

int Stack::peek(int index)
{
    int x = -1;
    /* Checking if the index is valid. */
    if (top - index + 1 < 0 || top - index + 1 == size)
    {
        cout << "Invalid position!" << endl;
    }
    else
    {
        /* Getting the element at the index from the top of the stack. */
        x = S[top - index + 1];
    }
    return x;
}

int Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void Stack::display()
{
    for (int i = top; i >= 0; i--)
    {
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}

int Stack::stackTop()
{
    if (isEmpty())
    {
        return -1;
    }
    return S[top];
}

int main()
{

    int A[] = {1, 3, 5, 7, 9};

    Stack stk(sizeof(A) / sizeof(A[0]));

    // Populate stack with array elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        stk.push(A[i]);
    }
    stk.push(11);

    cout << "Stack full: " << stk.isFull() << endl;

    // Display stack;
    cout << "Stack: " << flush;
    stk.display();

    // Peek
    cout << "Peek at 0th: " << stk.peek(0) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;

    // Top element
    cout << "Top element: " << stk.stackTop() << endl;

    // Pop out elements from stack
    cout << "Popped out elements: " << flush;
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();

    cout << "Stack empty: " << stk.isEmpty() << endl;

    return 0;
}