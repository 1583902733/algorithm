#include <vector>
#include <iostream>
using namespace std;

//输入n，输出(1,2,3,...,n)的全排列
class Permutation
{
public:
    Permutation(int n) : n(n)
    {
        permutations1();
    }
    void perm1(int m)
    {
        if (m == n - 1)
            result.push_back(p);
        else
        {
            for (int j = m; j < n; ++j)
            {
                int temp = p[j];
                p[j] = p[m];
                p[m] = temp;
                perm1(m + 1);
                p[m] = p[j];
                p[j] = temp;
            }
        }
    }

    void permutations1()
    {
        for (int i = 0; i < n; ++i)
        {
            p.push_back(i + 1);
        }
        perm1(0);
    }
    void print()
    {
        for (int i = 0; i < result.size(); ++i)
        {
            for (int j = 0; j < result[0].size(); ++j)
            {
                cout << result[i][j] << "  ";
            }
            cout << endl;
        }
    }

private:
    int n;
    vector<int> p;
    vector<vector<int>> result;
};

int main()
{
    int n = 0;
    cin >> n;
    Permutation A(n);
    A.print();
    return 0;
}
