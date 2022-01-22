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

bool symmetricalChecker(TreeNode* l, TreeNode* r)
{
    if(l==NULL || r==NULL)
        return l == r;

    if (l->data == r->data)
        return symmetricalChecker(l->left, r->right) && symmetricalChecker(l->right, r->left);
    else
        return false;
}

bool isSymmetrical(TreeNode* root)
{
    return root == NULL || symmetricalChecker(root->left, root->right);
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

    cout << "THE BINARY TREE IS: ";

    if(isSymmetrical(root))
        cout << "SYMMETRICAL";
    else
        cout << "ASYMMETRICAL";
}