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

int MaxWidth (Node* root)
{
    int ans;
    if(root==NULL)
        return ans;

    queue<pair<Node *, int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        int size = q.size();
        int min_index = q.front().second;

        for (int i = 0; i < size;i++)
        {
            auto it = q.front();
            q.pop();
            int curr_index = it.second;

            
        }
    }
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
}
