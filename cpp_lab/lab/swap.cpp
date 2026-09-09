#include <iostream>
using namespace std;

void swap(int &x, int &y)   // pass by reference
{
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10;
    int b = 20;

    cout << "before swap: a=" << a << " b=" << b << endl;
    swap(a, b);
    cout << "after swap: a=" << a << " b=" << b << endl;

    return 0;
}
