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
                flag = 1; // if swapping occurs, flag is set to 1
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

// Selection sort
void selectionSort(int A[], int n)
{
    int i, j, k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

// Merge sort
void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void mergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

// Quick sort
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j + 1, h);
    }
}

// Counting sort
void countingSort(int A[], int n)
{
    int i, j, max = A[0];
    for (i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    int *C = new int[max + 1];

    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (C[j] > 0)
        {
            A[i++] = j;
            C[j]--;
        }
        else
            j++;
    }
}

// Radix sort
int getDigit(int num, int k)
{
    int d;
    while (k > 0)
    {
        d = num % 10;
        num = num / 10;
        k--;
    }
    return d;
}

void radixSort(int A[], int n)
{
    int i, j, k, radix = 1, max = A[0];
    int *B = new int[n];

    for (i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    while (max / radix > 0)
    {
        int bucket[10] = {0};
        for (i = 0; i < n; i++)
            bucket[getDigit(A[i], radix)]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = n - 1; i >= 0; i--)
            B[--bucket[getDigit(A[i], radix)]] = A[i];
        for (i = 0; i < n; i++)
            A[i] = B[i];
        radix++;
    }
}

// // Bucket sort
// void bucketSort(int A[], int n)
// {
//     int i, j, k, buckets, divider;
//     int max = A[0];
//     for (i = 1; i < n; i++)
//     {
//         if (A[i] > max)
//             max = A[i];
//     }
//     cout << "Enter the number of buckets: ";
//     cin >> buckets;
//     divider = max / buckets + 1;
//     vector<int> B[buckets];

//     for (i = 0; i < n; i++)
//     {
//         j = A[i] / divider;
//         B[j].push_back(A[i]);
//     }
//     for (i = 0; i < buckets; i++)
//         sort(B[i].begin(), B[i].end());
//     for (i = k = 0; i < buckets; i++)
//     {
//         for (j = 0; j < B[i].size(); j++)
//             A[k++] = B[i][j];
//     }
// }

// Shell sort
void shellSort(int A[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

// Heap sort
void heapify(int A[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[l] > A[largest])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&A[0], &A[i]);
        heapify(A, i, 0);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A) / sizeof(A[0]);
    // bubbleSort(A, n);
    // selectionSort(A, n);
    // insertionSort(A, n);
    // mergeSort(A, 0, n - 1);
    // quickSort(A, 0, n);
    // countingSort(A, n);
    // radixSort(A, n);
    // bucketSort(A, n);
    // shellSort(A, n);
    heapSort(A, n);
    display(A, n);

    return 0;
}
