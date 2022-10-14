#include <bits/stdc++.h>

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }

    void createRef(int bit)
    {
        links[bit] = new Node();
    }

    Node *getNextNode(int bit)
    {
        return links[bit];
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        // check all bits from (bit-31 -> bit-0)
        for (int bit = 31; bit >= 0; bit--)
        {
            bool isSet = num & (1 << bit);
            if (!node->containsKey(isSet))
                node->createRef(isSet);
            node = node->getNextNode(isSet);
        }
    }

    int getMax(int val)
    {
        Node *node = root;
        int ans = 0;
        for (int bit = 31; bit >= 0; bit--)
        {
            bool isSet = val & (1 << bit);
            if (node->containsKey(!isSet))
            {
                node = node->getNextNode(!isSet);
                ans = ans | (1 << bit);
            }
            else
            {
                node = node->getNextNode(isSet);
            }
        }
        return ans;
    }
};

bool cmp(vector<int> v1, vector<int> v2)
{
    return v1[1] < v2[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int m = queries.size();
    vector<int> ans(m);
    // mark index for each query
    for (int i = 0; i < m; ++i)
        queries[i].push_back(i); // 3rd element is the index of the query
    // sort all queries according to Ai in increasing order
    sort(queries.begin(), queries.end(), cmp);
    // sort the array in increasing order
    sort(arr.begin(), arr.end());

    Trie *obj = new Trie(); // create a trie

    int ptr = 0;
    for (int i = 0; i < m; ++i)
    {
        auto query = queries[i];
        int Xi = query[0], Ai = query[1], idx = query[2];

        // increment the pointer for all elements <= Ai
        while (ptr < arr.size() && arr[ptr] <= Ai)
        {
            obj->insert(arr[ptr]);
            ptr++;
        }

        // insert max XOR into ans index
        ans[idx] = obj->getMax(Xi);
    }
    return ans;
}