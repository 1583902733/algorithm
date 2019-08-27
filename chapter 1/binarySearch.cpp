#include <iostream>
#include <vector>
using namespace std;

//a数组为递增数组
int binarySearch(vector<int> a, int x)
{
    int low = 0, high = a.size();
    int j = 0;
    while (low <= high && j == 0)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            j = mid;
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return j; //如果要返回为第几个元素，j+1即可
}

int main()
{
    vector<int> A = {1,3,4,5,7,9};
    cout<<binarySearch(A,4)<<endl;
    return 0;
}
