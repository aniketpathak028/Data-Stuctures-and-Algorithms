#include<iostream>
using namespace std;

struct Node {
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

bool isTreeSame(Node* tree1, Node*tree2)
{
    if(tree1==NULL || tree2==NULL)
        return tree1 == tree2;

    return (tree1->data==tree2->data)&&(isTreeSame(tree1->left, tree2->left) && isTreeSame(tree2->right, tree1->right));
}

int main ()
{
    Node *root;
    root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(8);

    Node *root1;
    root1 = new Node(5);
    root1->left = new Node(7);
    root1->right = new Node(8);
    root1->left->left = new Node(2);
    root1->right->left = new Node(1);
    root1->right->right = new Node(8);


    cout << "Both trees are: " << isTreeSame(root, root1);
}