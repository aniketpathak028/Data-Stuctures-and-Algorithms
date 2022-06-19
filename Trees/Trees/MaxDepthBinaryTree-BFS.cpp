// Find the Maximum depth of the binary tree using BFS

// T.C = O(N) as we have to travel all the nodes in order to find the max depth 
// S.C = O(N) as at the last level the queue will have max

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

int max_depth_bfs (Node* root)
{
    int ans=0;
    queue<Node *> q;

    if(root==NULL)
        return ans;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        ans++;

        while(size--)
        {
            Node *ele = q.front();
            q.pop();

            if(ele->left)
                q.push(ele->left);
                
            if(ele->right)
                q.push(ele->right);
        }

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

    int depth = max_depth_bfs(root);
    cout << "The max depth of this binary tree is: \n";
    cout << depth;
}
