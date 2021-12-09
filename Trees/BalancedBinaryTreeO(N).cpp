// Check whether a binary tree is balanced or not!
// T.C = O(N)
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

int depth (Node* root)
{
    if(root==NULL)
        return 0;

    int lh = depth(root->left);
    int rh = depth(root->right);

    if(lh==-1 || rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;

    return 1 + max(lh, rh);
}

bool CheckBalanced(Node* root)
{
    return depth(root)!=-1;
}

int main()
{
    Node *root;
    root = new Node(5);
    root->right = new Node(8);
    root->right->left = new Node(1);
    root->right->right = new Node(8);

    cout << "The binary Tree is " << CheckBalanced(root);
}