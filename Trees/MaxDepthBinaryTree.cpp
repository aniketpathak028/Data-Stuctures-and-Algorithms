// Find the Maximum depth of the binary tree using recursion

// T.C = O(N) as we have to travel all the nodes in order to find the max depth 
// S.C = O(N) if we have a skew tree / linear tree, the max height of auxiliary stack height is N.

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

int max_depth (Node* root)
{
    if(root==NULL)
        return 0;

    int lh = max_depth(root->left);
    int rh = max_depth(root->right);

    return 1 + max(lh, rh);
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

    int depth = max_depth(root);
    cout << "The max depth of this binary tree is: \n";
    cout << depth;
}
