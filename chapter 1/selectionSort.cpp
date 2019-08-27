#include <cstdio>
#include <vector>
using namespace std;

void selectionSort(vector<int> &A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int k = i; //k记录当前轮次最小值的下标
        for (int j = i + 1; j < n; ++j)
        {
            if (A[j] < A[k])
                k = j;
        }
        if (i != k)
        {
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
}

int main()
{
    vector<int> A = {0, 5, 3, 2};
    selectionSort(A);
    for (int i = 0; i < A.size(); ++i)
    {
        printf("%4d", A[i]);
    }
    return 0;
}
