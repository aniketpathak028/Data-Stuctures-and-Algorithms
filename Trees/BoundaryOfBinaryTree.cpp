// The problem statement is to print the boundary of a given binary tree in anticlockwise direction

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

bool leaf(Node* node)
{
    return !node->left && !node->right;
}

void LeftBoundary (Node* root, vector<int> &ans)
{
    root = root->left;
    while (root)
    {   
        if(!leaf(root))
            ans.push_back(root->data);

        root = root->left ? root->left : root->right;
    }
}

void RightBoundary (Node* root, vector<int> &ans)
{
    stack<int> s;
    root = root->right;
    while (root)
    {
        if(!leaf(root))
            s.push(root->data);
                                                                // O(H) + O(H) + O(N) = O(N) - T.C. , S.C = O(N)
        root = root->right ? root->right : root->left;
    }

    while(!s.empty()){
        int ele = s.top();
        s.pop();
        ans.push_back(ele);
    }
}

void LeafNodes (Node* root, vector<int> &ans)
{
    if(leaf(root)){
        ans.push_back(root->data);
        return;
    }
     
    LeafNodes(root->left, ans);
    LeafNodes(root->right, ans);
}

vector<int> PrintBoundary(Node*root)
{
    vector<int> ans;

    if(!root)
        return ans;

    if(!leaf(root))
        ans.push_back(root->data);

    LeftBoundary(root, ans);
    LeafNodes(root, ans);
    RightBoundary(root, ans);
    
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
    
    // 5 7 2 3 1 8 8

    auto ans = PrintBoundary(root);

    cout << "THE BOUNDARY TRAVERSAL IN ANTICLOCKWISE DIR. IS: \n";

    for(auto i: ans)
        cout << i<<" ";
}