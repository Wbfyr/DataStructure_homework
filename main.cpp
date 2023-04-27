#include <iostream>
using namespace std;

int main()
{
    int n = 1000;
    while (n)
    {
        cout << n << ' ' << '.' << ' ';
        n--;
    }
    return 0;
}