#include <bits/stdc++.h>
using namespace std;

int asc_binary_search(vector<int> &arr, int element)
{
    int start = 0, end = arr.size(), mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == element)
            return mid;
        else if (element < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int desc_binary_search(vector<int> &arr, int element)
{
    int start = 0, end = arr.size(), mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == element)
            return mid;
        else if (element < arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int oas(vector<int> &arr, int element){
    int start = 0, end = arr.size() - 1;
    if(arr[start]<=arr[end])
        return asc_binary_search(arr, element);
    else
        return desc_binary_search(arr, element);
}

int main()
{
    vector<int> arr = {2, 3, 4, 9, 11, 23};
    cout << oas(arr, 11);
    return 0;
}