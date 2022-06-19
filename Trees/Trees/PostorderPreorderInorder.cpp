// Finding the preorder, postorder and inorder of a binary tree at once!

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> preorder, postorder, inorder;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
    }
};

void ppi (Node* root)
{
    if(root == NULL)
        return;

    stack<pair<Node *, int>> st;

    st.push({root, 1});

    while(!st.empty())
    {
        pair<Node *, int> p;
        p = st.top();
        st.pop();

        if(p.second==1)
        {
            preorder.push_back(p.first->data);
            p.second++;
            st.push(p);

            if(p.first->left!=NULL)
            {
                st.push({p.first->left,1});
            }
        }

        else if(p.second == 2)
        {
            inorder.push_back(p.first->data);
            p.second++;
            st.push(p);

            if(p.first->right!=NULL)
            {
                st.push({p.first->right,1});
            }
        }

        else
        {
            postorder.push_back(p.first->data);
        }
    }
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

    ppi(root);

    cout << "PREORDER: \n";
    for(auto i: preorder)
        cout << i << " ";
    cout << endl;

    cout << "POSTORDER: \n";
    for(auto i: postorder)
        cout << i << " ";
    cout << endl;

    cout << "INORDER: \n";
    for(auto i: inorder)
        cout << i << " ";
    cout << endl;
}
