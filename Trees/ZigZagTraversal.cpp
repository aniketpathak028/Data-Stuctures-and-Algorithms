#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> ZigZagTraversal(TreeNode* node)
{
    vector<vector<int>> ans;

    if(node==NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(node);

    bool leftToRight = true;

    while (!q.empty())
    {
        
        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size;i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;
    
            row[index] = temp->data;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        ans.push_back(row);
        leftToRight = !leftToRight;
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans;
    ans = ZigZagTraversal(root);

    cout << "THE ZIG-ZAG TRAVERSAL OF THE TREE IS: \n";

    for(auto i:ans){
        for(auto j: i)
                cout << j << " ";
    }
}