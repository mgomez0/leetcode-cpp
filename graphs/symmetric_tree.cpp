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

    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 */

#include "TreeNode.h"
#include <bits/stdc++.h>

class Solution {
public:
    bool result;
    bool isSymmetric(TreeNode* root){
        return dfs(root, root);
    }

    bool dfs(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(root1->val != root2->val) return false;
        return (root1->val == root2->val) && dfs(root1->right, root2->left) && dfs(root1->left, root2->right);
    }
};