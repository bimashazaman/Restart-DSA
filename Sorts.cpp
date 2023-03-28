#include <iostream>

using namespace std;

// swap function
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort
void bubbleSort(int A[], int n)
{
    int i, j, temp, flag = 0;

    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

// Insertion sort
void insertionSort(int A[], int n)
{
    int i, j, x; // x is the element to be inserted

    /* Sorting the array A in ascending order. */
    for (i = 1; i < n; i++)
    {
        j = i - 1; // j is the index of the last element of the sorted subarray
        x = A[i];  // x is the element to be inserted
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j]; // shifting the elements to the right
            j--;             // decrementing j
        }                    // end of while loop
        A[j + 1] = x;        // inserting x at the correct position
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    bubbleSort(A, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
