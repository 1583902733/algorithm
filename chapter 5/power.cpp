#include <cstdio>

int power(int x, int m)
{
    int y = 0;
    if (m == 0)
        y = 1;
    else
    {
        y = power(x, m / 2);
        y = y * y;
        if (m % 2 == 1)
            y = x * y;
    }
    return y;
}

int main()
{
    int x = 4, m = 4;
    printf("%d\n", power(x, m));
    return 0;
}
