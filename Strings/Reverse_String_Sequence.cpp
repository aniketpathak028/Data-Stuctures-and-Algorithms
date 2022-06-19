// Problem Statement:

// Given a string containing a sequence of words, separated by spaces (any number of spaces may be there)
// reverse the words of the string preserving the spaces

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input = "this problem  is   not  very hard"; 

    vector<string> words; //  vector to store all the words
    vector<int> space_cnt; // vector to store the space count in between the words

    string word = "";
    int space = 0;

    for (int i = 0; i < input.size(); ++i)
    {
        if (i > 0 && (input[i] == ' ' && input[i - 1] != ' '))
        {
            space++;
            words.push_back(word);
            word = "";
        }
        else if (input[i] != ' ')
        {
            if (i > 0 && input[i - 1] == ' ')
            {
                space_cnt.push_back(space);
                space = 0;
            }
            word += input[i];
        }
        else
            space++;
    }

    words.push_back(word); // push the last word

    reverse(words.begin(), words.end()); // reverse the order of words

    string ans = "";

    for (int i = 0; i < words.size(); ++i)
    {
        if (i == words.size() - 1)
        {
            ans += words[i];
            break;
        }
        ans += words[i];
        int spaces = space_cnt[i];
        while (spaces--)
            ans += ' ';
    }

    cout << endl;
    cout << ans;

    return 0;
}