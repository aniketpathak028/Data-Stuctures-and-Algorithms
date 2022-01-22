#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector <int>> VerticalOrderTraversal(Node* root)
{
    vector<vector<int>> ans;

    map < int, map<int, multiset<int>>> nodes;
    queue<pair<Node *,pair<int,int>>> q;


    if(root==NULL)
        return ans;

    q.push({root,{0,0}});

    while(!q.empty())
    {
        int size = q.size();

        while(size--)
        {
            auto ele = q.front();
            q.pop();

            int x = ele.second.first;
            int y = ele.second.second;

            nodes[x][y].insert(ele.first->data);

            if(ele.first->left){
                q.push({ele.first->left, {x-1, y+1}});
            }

            if(ele.first->right){
                q.push({ele.first->right, {x+1, y+1}});
            }
        }
    }


        for(auto i: nodes)
        {
            vector<int> col;
            for(auto j: i.second)
            {
               for(auto it: j.second){
                   col.push_back(it);
               }
            }
            ans.push_back(col);
         }

         return ans;
}

int main()
{
    Node *root;
    root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(8);

    auto ans = VerticalOrderTraversal(root);

    cout << "THE VERTICAL ORDER TRAVERSAL IS: \n";
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

}