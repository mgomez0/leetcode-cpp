/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
Runtime: 60 ms, faster than 28.56% of C++ online submissions for N-ary Tree Postorder Traversal.
Memory Usage: 11.2 MB, less than 69.03% of C++ online submissions for N-ary Tree Postorder Traversal.
*/
#include "Node.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> result;
    vector<int> postorder(Node* root) {
        dfs(root);
        return result;
        
    }
    
    void dfs(Node* root)
    {
        if(!root) return;
        for(auto i: root->children)
        {
            dfs(i);
        }
        result.push_back(root->val);
    }
};