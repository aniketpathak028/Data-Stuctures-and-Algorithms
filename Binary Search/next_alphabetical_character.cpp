#include<bits/stdc++.h>
using namespace std;

char nextChar(vector<char> &characters, char ch){
    int s = 0, e = characters.size() - 1, mid;
    char res;
    while(s<=e){
        mid = s + (e - s) / 2;
        
        if(characters[mid]>ch){
            res = characters[mid];
            e = mid - 1;
        }
        else
            s = mid + 1;
    }

    return res;
}

int main(){
    vector<char> characters = {'a', 'b', 'd', 'e', 'f', 'h'};
    cout << nextChar(characters, 'b');
    return 0;
}