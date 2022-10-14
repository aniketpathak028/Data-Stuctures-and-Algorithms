#include<bits/stdc++.h>
using namespace std;

int first(vector<int> &arr, int element){
    int start = 0, end = arr.size() - 1, mid, res = -1;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(arr[mid]==element){
            res = mid;
            end = mid - 1;
        }
        else if(element<arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return res;
}

int last(vector<int> &arr, int element)
{
    int start = 0, end = arr.size() - 1, mid, res = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == element)
        {
            res = mid;
            start = mid + 1;
        }
        else if (element>arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return res;
}

int main(){
    vector<int> arr = {1, 2, 3, 8, 8, 8, 35};
    cout << first(arr, 8) << " " << last(arr, 8);
    return 0;
}