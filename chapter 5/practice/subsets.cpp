#include <vector>
#include <iostream>
using namespace std;

//输入n，输出(1,2,3,...,n)的所有子集
class Permutation
{
private:
    int n;
    vector<int> p;
    vector<vector<int>> result;

public:
    Permutation(int n) : n(n)
    {
        perm1(0);
    }
    void perm1(int m)
    {
        result.push_back(p);
        if (m == n)
            return;
        else
        {
            for (int j = m; j < n; ++j)
            {
                p.push_back(j + 1);
                perm1(j + 1);
                p.pop_back();
            }
        }
    }

    void print()
    {
        for (int i = 0; i < result.size(); ++i)
        {
            for (int j = 0; j < result[i].size(); ++j)
            {
                cout << result[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

//第二种方法，利用位运算
vector<vector<int>> subsets(vector<int> &nums)
{
    int S = nums.size();
    int N = 1 << S;
    vector<vector<int>> res;
    for (int i = 0; i < N; ++i)
    {
        vector<int> v;
        for (int j = 0; j < S; ++j)
            if (i & (1 << j))
                v.push_back(nums[j]);
        res.push_back(v);
    }
    return res;
}

int main()
{
    int n = 0;
    cin >> n;
    Permutation A(n);
    A.print();
    return 0;
}
