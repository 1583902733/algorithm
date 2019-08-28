#include <cstdio>
#include <vector>
using namespace std;

//合并一个数组中两段有序序列，p为第一个序列起点的检索，q为第一个序列的终点检索，r为第二个序列的终点检索
void merge(vector<int> &A, int p, int q, int r)
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
    for (vector<int>::iterator iter = B.begin(); iter != B.end(); iter++)
    {
        A[i] = *iter;
        i++;
    }
}

void bottomUpSort(vector<int> &A)
{
    int t = 1, n = A.size();
    while (t < n)
    {
        int s = t, i = 0;
        t = 2 * s;
        while (i + t <= n-1)
        {
            merge(A, i, i + s-1, i + t-1);
            i = i + t;
        }
        if (i + s < n-1)
            merge(A, i, i + s-1, n-1);
    }
}

int main(){
    vector<int> vec = {6,10,9,5,3,11,4,8,1,2,7};
    bottomUpSort(vec);
    for(int i=0;i<vec.size();++i){
        printf("%4d",vec[i]);
    }
    printf("\n");
    return 0;
}
