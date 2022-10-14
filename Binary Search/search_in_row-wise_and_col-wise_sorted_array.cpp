#include<bits/stdc++.h>
using namespace std;

// T.C = O(n+m)

pair<int,int> search(vector<vector<int>> mat, int ele){
    int i = 0, j = mat[0].size() - 1;
    while(i>=0 && i<mat.size() && j>=0 && j<mat[0].size()){
        if(mat[i][j]==ele)
            return {i, j};
        else if(mat[i][j]>ele)
            j--;
        else
            i++;
    }
    return {-1, -1};
}

int main(){
    // row-wise and col-wise sorted matrix
    vector<vector<int>> mat = {  {10, 20, 30, 40}, 
                                 {15, 25, 35, 45},
                                 {27, 29, 37, 48}, 
                                 {32, 33, 39, 50} };

    cout << search(mat, 29).first<<" "<<search(mat, 29).second;
    return 0;
}