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

void preorder(Node* root) //T.C = O(N) , S.C = O(N)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) //T.C = O(N) , S.C = O(N)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root) //T.C = O(N) , S.C = O(N)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

vector<vector <int>> bfs(Node* root) //T.C = O(N) , S.C = O(N)
{
    vector<vector<int>> ans;
    queue<Node *> q;

    if(root==NULL)
        return ans;

    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;

        while(size--)
        {
            Node *ele = q.front();
            q.pop();

            if(ele->left)
                q.push(ele->left);

            if(ele->right)
                q.push(ele->right);

            level.push_back(ele->data);
        }

        ans.push_back(level);
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

    vector<vector<int>> level_order_traversal = bfs(root);

    cout << "PREORDER: \n";
    preorder(root);
    cout << endl;

    cout << "POSTORDER: \n";
    postorder(root);
    cout << endl;

    cout << "INORDER: \n";
    inorder(root);
    cout << endl;

    cout << "LEVEL-ORDER-TRAVERSAL(BFS): \n";

    for(auto i: level_order_traversal)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
    }
}