
#include <stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

int binarySearch(struct Array arr, int key)
{
    int l, h, mid;

    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid - 1;
        }
    }

    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }

    return -1;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;

    /* Returning the max value of the array. */
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            return max = arr.A[i];
        }

        return max;
    }
}

int Sum(struct Array arr)
{
    int s = 0;
    int i;

    /* Returning the sum of the array. */
    for (i = 0; i < arr.length; i++)
    {
        s += arr.A[i];
    }

    return s;
}

int Avg(struct Array arr)
{
    return Sum(arr) / arr.length;
}

int Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        return arr->A[index] = x;
    }

    return -1;
}

int deleteAtGivenIndex(struct Array *arr, int givenIndex)
{
    int x = 0, i;
    if (givenIndex >= 0 && givenIndex < arr->length)
    {
        x = arr->A[givenIndex];
        for (i = givenIndex; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }

        arr->length--;
        return x;
    }

    return 0;
}

int linearSearch(struct Array arr, int key)
{
    int i;

    for (i = 0; i < arr.length; i++)
    {
        if (key = arr.A[i])
        {
            return i;
        }

        return -1;
    }
}

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}
void Insert(struct Array *arr, int index, int x)
{
    int i;

    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}

void insertPracticeOnceAgain(struct Array *arr, int index, int x)
{
    int i;

    if (index >= 0 && index <= arr->length)
    {
        /* Shifting the elements to the right. */
        for (i = arr->length; i > index; i--)
        {
            /* Shifting the elements to the right. */
            arr->A[i] = arr->A[i - 1];
        }
        /* Assigning the value of x to the index of the array. */
        arr->A[index] = x;
        /* Incrementing the length of the array. */
        arr->length++;
    }
}
int main()
{
    struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr1, 10);
    Insert(&arr1, 0, 12);
    Display(arr1);
    return 0;
}