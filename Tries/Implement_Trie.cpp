#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag;

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    Node* getNextRef(char ch){
        return links[ch - 'a'];
    }

    void createRef(char ch){
        links[ch - 'a'] = new Node();
    }
};

class Trie{
    Node *root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *node = root;
        for (int i = 0; i < word.size(); ++i){
            if(!node->containsKey(word[i])) node->createRef(word[i]);   
            node = node->getNextRef(word[i]);
        }
        node->flag = true;
    }

    bool search(string word){
        Node *node = root;
        for (int i = 0; i < word.length(); ++i){
            if (!node->containsKey(word[i]))
                return false;
            node = node->getNextRef(word[i]);
        }
        return node->flag;
    }

    bool startsWith(string prefix){
        Node *node = root;
        for (int i = 0; i < prefix.size(); ++i){
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->getNextRef(prefix[i]);
        } 
        return true;
    }
};

int main(){
    vector<string> words= {"apple", "appx", "pine", "seuxtt"};
    Trie obj = Trie();
    for(auto word: words)
        obj.insert(word);

    cout << obj.search("apple") << " "<< obj.startsWith("app")<<" "<<obj.search("seu")<<" "<<obj.startsWith("pi");

    // 1 1 0 1

    return 0;
}