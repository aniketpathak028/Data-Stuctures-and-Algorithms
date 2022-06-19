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

// vector<int> TopView(Node* root)
// {
//     vector<int> ans;

//     map < int, map<int, multiset<int>>> nodes;
//     queue<pair<Node *,pair<int,int>>> q;


//     if(root==NULL)
//         return ans;

//     q.push({root,{0,0}});

//     while(!q.empty())
//     {
//         int size = q.size();

//         while(size--)
//         {
//             auto ele = q.front();
//             q.pop();

//             int x = ele.second.first;
//             int y = ele.second.second;

//             nodes[x][y].insert(ele.first->data);

//             if(ele.first->left){
//                 q.push({ele.first->left, {x-1, y+1}});
//             }

//             if(ele.first->right){
//                 q.push({ele.first->right, {x+1, y+1}});
//             }
//         }
//     }

//      for(auto i: nodes)
//         {
//             vector<int> col;
//             for(auto j: i.second)
//             {
//                for(auto it: j.second){
//                    col.push_back(it);
//                }
//             }
//             ans.push_back(col[0]);
//         }

//         return ans;
// }

vector<int> TopView(Node* root)
{
    vector<int> ans;

    if(root==NULL)
        return ans;

    map<int, int> m;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        int size = q.size();

        while(size--)
        {
            auto temp = q.front();
            q.pop();

            int line = temp.second;

            if(!m[line])
                m[line] = temp.first->data;

            if(temp.first->left)
                q.push({temp.first->left, line-1});

            if(temp.first->right)
                q.push({temp.first->right, line + 1});
        }
    }

    for(auto i: m)
    {
        ans.push_back(i.second);
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

    // T.V = 

    vector<int> ans = TopView(root);

    for(auto i: ans){
        cout << i<<" ";
    }
}