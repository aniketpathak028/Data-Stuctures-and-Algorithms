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

// int ChildrenSumProperty(Node* root)
// {
//     if(root->left==NULL && root->right==NULL)
//         return root->data;

//     if(root->data >( root->left->data + root->right->data)){
//         root->left->data = root->data;
//         root->right->data = root->data;
//     }

//     if(root->data < (root->left->data + root->right->data))
//         root->data = root->left->data + root->right->data;

//     int l = !root->left? 0 : ChildrenSumProperty(root->left);
//     int r = !root->right? 0: ChildrenSumProperty(root->right);
//     root->data = l + r;
//     return root->data;
// }

void printTree(Node *root)
{
    if(!root)
        return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

void reorder(Node* root) {
    if(root == NULL) return; 
    int child = 0;
    if(root->left) {
        child += root->left->data; 
    }
    if(root->right) {
        child += root->right->data; 
    }
    
    if(child >= root->data) root->data = child; 
    else {
        if(root->left) root->left->data = root->data; 
        else if(root->right) root->right->data = root->data; 
    }
    
    reorder(root->left); 
    reorder(root->right); 
    
    int tot = 0; 
    if(root->left) tot += root->left->data; 
    if(root->right) tot+= root->right->data; 
    if(root->left or root->right) root->data = tot;  
}

void changeTree(Node*root) {
    reorder(root); 
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

    // int ans = ChildrenSumProperty(root);
    // cout << ans;
    printTree(root);
    cout << endl;
    changeTree(root);
    printTree(root);
}
