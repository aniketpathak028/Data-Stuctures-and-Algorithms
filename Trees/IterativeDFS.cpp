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

vector<int> iterative_preorder(Node* root) //T.C = O(N) , S.C = O(N)
{
    vector<int> ans;
    if(root == NULL)
        return ans;

    stack<Node *> st;
    st.push(root);

    while(!st.empty())
    {
        Node *ele = st.top();
        st.pop();

        ans.push_back(ele->data);

        if(ele->right!= NULL)
            st.push(ele->right);

        if(ele->left!= NULL)
            st.push(ele->left);
    }

    return ans;
}

vector<int> iterative_inorder(Node* root)  //T.C = O(N) , S.C = O(N)
{
    vector<int> ans;
    if(root == NULL)
        return ans;

    stack<Node *> st;
    Node *node = root;

    while(true)
    {
        if(node==NULL)
        {
            if(st.empty())
                break;
            node = st.top();
            st.pop();

            ans.push_back(node->data);
            node = node->right;
        } else {
            st.push(node);
            node = node->left;
        }
    }

    return ans;
}

vector<int> iterative_postorder(Node* root)  // ITERATIVE POSTORDER USING 1 STACK T.C = O(N) , S.C = O(2N + C)
{
    vector<int> ans;
    if(root == NULL)
        return ans;

    stack<Node *> st1;
    stack<int> st2;
    st1.push(root);

    while(!st1.empty())
    {
        root = st1.top();

        st1.pop();
        st2.push(root->data);

        if(root->left)
            st1.push(root->left);
        if(root->right)
            st1.push(root->right);
    }

    while(!st2.empty())
    {
        int ele = st2.top();
        st2.pop();
        ans.push_back(ele);
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

    vector<int> it_preorder;
    vector<int> it_postorder;
    vector<int> it_inorder;

    cout << "PREORDER: \n";
    it_preorder= iterative_preorder(root);
    for(auto i: it_preorder)
        cout << i << " ";
    cout << endl;

    cout << "POSTORDER: \n";
    it_postorder= iterative_postorder(root);
    for(auto i: it_postorder)
        cout << i << " ";
    cout << endl;

    cout << "INORDER: \n";
    it_inorder= iterative_inorder(root);
    for(auto i: it_inorder)
        cout << i << " ";
    cout << endl;
}