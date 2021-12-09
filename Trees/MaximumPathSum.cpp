#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MaxPath = 0;

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

int MaxPathSum(Node* root)
{
    if(root==NULL)
        return 0;

    int ls = MaxPathSum(root->left);
    int rs = MaxPathSum(root->right);

    MaxPath = max(MaxPath, (root->data) + ls + rs);

    return root->data + max(ls, rs);
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

    int ans = MaxPathSum(root);

    cout << "The maximum sum path is: " << MaxPath;
}
