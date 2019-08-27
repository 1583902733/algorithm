#include <cstdio>
#include <vector>
using namespace std;

//A为vector<int>，p为起点，q为第一段序列的终点，r为第二段序列的终点；这两段序列都为不减序列。
vector<int> merge(vector<int> A, int p, int q, int r)
{
    int s = p, t = q + 1;
    vector<int> B;
    while (s <= q && t <= r)
    {
        if (A[s] <= A[t])
        {
            B.push_back(A[s]);
            s++;
        }
        else
        {
            B.push_back(A[t]);
            t++;
        }
    }
    if (s == q + 1)
    {
        while (t <= r)
        {
            B.push_back(A[t]);
            t++;
        }
    }
    else
    {
        while (s <= q)
        {
            B.push_back(A[s]);
            s++;
        }
    }
    return B;
}

//merge2只是将merge改为在原数组上修改而不是返回一个新数组，将在Bottom-Up Merge Sorting中用到。
void merge2(vector<int>& A, int p, int q, int r)
{
    int s = p, t = q + 1;
    vector<int> B;
    while (s <= q && t <= r)
    {
        if (A[s] <= A[t])
        {
            B.push_back(A[s]);
            s++;
        }
        else
        {
            B.push_back(A[t]);
            t++;
        }
    }
    if (s == q + 1)
    {
        while (t <= r)
        {
            B.push_back(A[t]);
            t++;
        }
    }
    else
    {
        while (s <= q)
        {
            B.push_back(A[s]);
            s++;
        }
    }
    int i = p;
    for(vector<int>::iterator iter=B.begin();iter!=B.end();iter++){
        A[i]=*iter;
        i++;
    }
}

int main()
{
    vector<int> A = {1, 2, 4, 5, 2, 3, 6, 7};
    //vector<int> ans = merge(A, 0, 3, 7);
    merge2(A,0,3,7);
    for (int i = 0; i < A.size(); ++i)
    {
        printf("%4d\n", A[i]);
    }
    return 0;
}
