#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};

void markParents(Node* root, unordered_map<Node*, Node*> &parent_track, Node* target) {
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()) { 
            Node* current = queue.front(); 
            queue.pop();
            if(current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

vector<int> distanceK(Node* root, Node* target, int k) {
        unordered_map<Node*, Node*> parent_track; // node -> parent
        markParents(root, parent_track, target); 
        
        unordered_map<Node*, bool> visited; 
        queue<Node*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                Node* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            Node* current = queue.front(); queue.pop();
            result.push_back(current->data);
        }
        return result;
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

    vector<int> result = distanceK(root, root->left->left, 2);

    for(auto i: result)
        cout << i << " ";
}
