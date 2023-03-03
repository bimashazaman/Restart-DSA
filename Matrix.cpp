#include <iostream>

using namespace std;

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    /* Setting the value of the diagonal element. */
    if (i == j)
        m->A[i - 1] = x;
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

// lower triangular matrix

void lowerTriangularMatrix()
{
    int A[10][10];
    int i, j, x;
    cout << "Enter the dimension of the matrix: ";
    cin >> x;
    cout << "Enter the elements of the matrix: " << endl;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "The lower triangular matrix is: " << endl;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            if (i >= j)
                cout << A[i][j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                cout << m.A[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    struct Matrix m;
    m.n = 4;
    m.A = new int[m.n];
    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);
    cout << Get(m, 2, 2) << endl;
    Display(m);
    return 0;
}
