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

bool Root2NodePath (TreeNode* root, vector<int> &ans, int x)
{
    if(root==NULL)
        return false;

    ans.push_back(root->data);

    if(root->data==x)
        return true;

    if(Root2NodePath(root->left,ans,x) || Root2NodePath(root->right,ans,x))
        return true;

    ans.pop_back();
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    vector<int> ans;
    Root2NodePath(root, ans, 3);

    cout << "THE PATH FROM ROOT TO NODE IS: \n";
    for(auto i: ans)
        cout << i << " ";
}
