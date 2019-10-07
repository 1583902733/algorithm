//出自https://github.com/zhedahht/ChineseCodingInterviewAppendix/blob/master/StreamMedian/StreamMedian.cpp

#include <algorithm>
#include <vector>
#include <functional>
#include<iostream>
using namespace std;

template <typename T>
class DynamicArray
{
public:
    void Insert(T num)
    {
        if (((min.size() + max.size()) & 1) == 0)
        {
            if (max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());

                num = max[0];

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
        else
        {
            if (min.size() > 0 && min[0] < num)
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }

    float GetMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
            throw  "No numbers are available";
        float median = 0;
        if ((size & 1) == 1)
            median = min[0];
        else
            median = ((float)min[0] + (float)max[0]) / 2;

        return median;
    }

private:
    vector<T> min;
    vector<T> max;
};

int main()
{
    int n;
    cin >> n;
    int x(0);
    DynamicArray<int>  solution;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        solution.Insert(x);
    }
    cout << "The midian is : " << solution.GetMedian() << endl;
    return 0;
}
