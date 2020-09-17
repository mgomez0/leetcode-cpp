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
    int left_subtree_depth = 1;
    int right_subtree_depth = 1;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root->left);
        dfs(root->right);
        
    }

    void dfs(TreeNode* root){
        if(!root) return;
        left_subtree_depth++;
        if()

    }
};