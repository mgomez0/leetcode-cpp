/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        dfs(root);
        return result;
    }
    
    void dfs(TreeNode* root){
        if(root->left)
        {
            dfs(root->left);
        }
        
        result.push_back(root->val);
        
        if(root->right)
        {
            dfs(root->right);
        }
        
    }
};