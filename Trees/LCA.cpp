// Find the Lowest Common Ancestor of two nodes in a Binary Tree

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

int LCA(Node* root, int a, int b)
{
    if(!root)
        return NULL;

    if(root->data==a || root->data==b)
        return root->data;

    int left = LCA(root->left, a, b);
    int right = LCA(root->right, a, b);

    if(left && right)
        return root->data;

    if(!left || !right)
        return (!left ? right : left);

    return NULL;
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

    int ans = LCA(root, 7, 8);
    cout << "THE LCA of 7 and 8 is " << ans;
}
