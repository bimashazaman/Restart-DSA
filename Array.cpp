
#include <iostream>

using namespace std;

int main()
{

   int A[10] = {2, 4, 6, 8, 96};

   /* Printing the first 10 elements of the array A. */
   for (int i = 0; i < 10; i++)
   {
      cout << A[i] << endl;
   };

   /* A for loop that iterates through the array A. */
   for (int x : A)
   {
      cout << x << endl;
   }

   return 0;
}
