#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Rectangle {
    int len;
    int br;
};

int area(struct Rectangle r) {
    return r.len * r.br;
}

int main() {

    Rectangle r = {4, 4};

    int a = area(r);

    cout<<r.len<<r.br<<a;
    return 0;
}