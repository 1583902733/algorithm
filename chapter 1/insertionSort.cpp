#include <cstdio>
#include <vector>
using namespace std;

//每次将一个数插入到前面已经排好的序列中
void insertionSort(vector<int> &A)
{
    int n = A.size();
    for (int i = 1; i < n; ++i)
    {
        int x = A[i];
        int j = i - 1;
        while (j > 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    vector<int> A = {0, 5, 3, 2,1,7};
    insertionSort(A);
    for (int i = 0; i < A.size(); ++i)
    {
        printf("%4d", A[i]);
    }
    return 0;
}
