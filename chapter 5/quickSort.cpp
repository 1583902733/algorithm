#include <iostream>
using namespace std;

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int key = arr[left];
        int i = left, j = right;
        while (i < j)
        {
            while (arr[j] > key && j > i) //arr[j] > key可以换为arr[j] >= key，但j > i不可以换为j >= i，边界问题
                j--;
            if (i < j)
                arr[i++] = arr[j];
            while (arr[i] < key && i < j)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = key;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}
int main()
{
    int a[] = {3, 7, 1, 2, 8, 4, 10};
    quickSort(a, 0, 7);
    for (int i = 0; i < 7; ++i)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
    return 0;
}
