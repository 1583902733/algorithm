#include <iostream>
using namespace std;

//a[]为表示多项式系数的数组，a0,a1,...,an;  n表示最高次幂。
int horner(int a[], int n, int x)
{
    int p = a[n];
    for (int i = 1; i <= n; ++i)
    {
        p = x * p + a[n - i];
    }
    return p;
}

int main()
{
    int a[4] = {1, 1, 1, 1}, n = 3;
    int x = 2;
    cout << horner(a, 3, x) << endl;
    return 0;
}
