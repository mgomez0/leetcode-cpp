/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * 
 * 
Runtime: 16 ms, faster than 88.84% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.8 MB, less than 22.98% of C++ online submissions for Validate Binary Search Tree.
 * };
 */
#include "TreeNode.h"
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool result = false;
    vector<int> inorder;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        dfs(root);
        for(int i = 0; i < inorder.size() - 1; i++)
        {
            if(inorder[i] >= inorder[i+1])
            {
                return result;
            }
        }
        result = true;
        return result;
        
    }
    
    void dfs(TreeNode* root)
    {
        if(!root) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
};