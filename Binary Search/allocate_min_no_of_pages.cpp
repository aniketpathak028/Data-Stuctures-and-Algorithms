#include<bits/stdc++.h>
using namespace std;

// to check if distribution is possible or not
bool isValid(vector<int> &books, int k, int maxi){
    int cnt = 1, sum = 0;
    for(auto &book: books){
        sum += book;
        if(sum>maxi){
            cnt++;
            sum = book;
        }
        if(cnt>k) return false;
    }
    return true;
}

int allocateMinBooks(vector<int> &books, int k){
    // if the number of books is less than the number of students
    if(books.size()<k)
        return -1;
    // find maximum element and total sum
    int maxi = INT_MIN, sum = 0;
    for(auto &book: books){
        sum += book;
        maxi = max(maxi, book);
    }
    // apply binary-search on answer
    int start = maxi, end = sum;
    int mid, res;
    while(start<=end){
        mid = start + (end - start) / 2;
        if(isValid(books, k, mid)){
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return res;
}

int main(){
    vector<int> books = {20, 10, 30, 40};
    cout << allocateMinBooks(books, 3);
    return 0;
}