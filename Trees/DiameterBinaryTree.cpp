#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Diameter = 0;
int maxi = 0;

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

int MaxHeight(Node* root)
{
    if(root==NULL)
        return 0;  // O(N) Time Complexity, O(N) space complexity for auxiliary stack for skew tree

    int lh = MaxHeight(root->left);
    int rh = MaxHeight(root->right);

    Diameter = max(Diameter, lh + rh);

    return 1 + max(lh , rh);
}

void DiameterBinary (Node* root)
{
    if(root==NULL)
        return;

    int lh = MaxHeight(root->left);  // O(N^2) TIME COMPLEXITY
    int rh = MaxHeight(root->right);

    maxi = max(maxi, lh + rh);

    DiameterBinary(root->left);
    DiameterBinary(root->right);
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

    int ans = MaxHeight(root);

    cout << "The Diameter of the tree is: \n"
         << Diameter<<endl;

    DiameterBinary(root);

    cout << "The Diameter of the tree is: \n"
         << maxi;
}