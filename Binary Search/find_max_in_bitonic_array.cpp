#include <bits/stdc++.h>
using namespace std;

int search_in_bitonic(vector<int> &arr, int key)
{
    int start = 0, end = arr.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        if (mid > 0 && mid < arr.size() - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                if (key <= arr[mid - 1])
                    end = mid - 1;
                else if (key <= arr[mid + 1])
                    start = mid + 1;
                else if (key > arr[mid])
                    return -1;
            }
            else if (arr[mid + 1] > arr[mid])
            {
                if (key > arr[mid])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else
            {
                if (key > arr[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (arr[1] == key)
                return 1;
            else
                return -1;
        }
        else
        {
            if (arr[arr.size() - 2] == key)
                return arr.size() - 2;
            else
                return -1;
        }
    }
    return -1;
}

int main()
{
    vector<int> bitonic_array = {1, 3, 4, 6, 9, 14, 11, 7, 2, -4, -9};
    cout << search_in_bitonic(bitonic_array, 6) << endl;
    cout << search_in_bitonic(bitonic_array, 4);
    return 0;
}
