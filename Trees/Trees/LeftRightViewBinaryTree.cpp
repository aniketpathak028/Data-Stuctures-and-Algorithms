#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> left_view, right_view;

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

void LeftView (Node* root, int level)
{
    if (root == NULL)
        return;

    if(level== left_view.size())
        left_view.push_back(root->data);

    LeftView(root->left, level + 1);
    LeftView(root->right, level + 1);
}

void RightView (Node* root, int level)
{
    if (root == NULL)
            return;

    if(level== right_view.size())
        right_view.push_back(root->data);

    RightView(root->right, level + 1);
    RightView(root->left, level + 1);
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

    LeftView(root, 0);
    RightView(root, 0);

    cout << "THE LEFT VIEW IS: \n";
    for(auto i: left_view){
        cout << i << " ";
    }
    cout << endl;

    cout << "THE RIGHT VIEW IS: \n";
    for(auto i: right_view){
        cout << i << " ";
    }
    cout << endl;
}