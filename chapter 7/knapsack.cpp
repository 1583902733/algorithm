#include <iostream>
using namespace std;

int solution(int n, int u[], int s[], int v)
{
    int V[n + 1][v + 1];
    for (int i = 0; i <= n; ++i)
    {
        V[i][0] = 0;
    }
    for (int i = 0; i <= v; ++i)
    {
        V[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= v; ++j)
        {
            V[i][j] = V[i - 1][j];
            if (s[i - 1] <= j)
            {
                V[i][j] = V[i][j] >= V[i - 1][j - s[i - 1]] + u[i] ? V[i][j] : V[i - 1][j - s[i - 1]] + u[i - 1];
            }
        }
    }
    return V[n][v];
}

int main()
{
    int n;
    cout << "Input n :";
    cin >> n;
    cout << "Input u[n] :";
    int u[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> u[i];
    }
    cout << "Input s[n] :";
    int s[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    int C;
    cout << "Input C :";
    cin >> C;
    cout << "Max value : " << solution(n, u, s, C) << endl;
    return 0;
}
