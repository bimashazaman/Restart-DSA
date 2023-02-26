#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Rectangle
{
public:
    int len;
    int br;

    Rectangle(int l, int b)
    {
        len = l;
        br = b;
    }

    /**
     * The function area() returns the area of a rectangle
     *
     * @return The area of the rectangle.
     */
    int area()
    {
        return len * br;
    }
};

int main()
{

    Rectangle r(2, 4);
    int c = r.area();

    cout << c;

    return 0;
}