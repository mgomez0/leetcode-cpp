/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        
        if(root == p || root == q)
        {
            return root;
        }

        TreeNode* left_tree_search_result = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_tree_search_result = lowestCommonAncestor(root->right, p, q);

        if(!left_tree_search_result) return right_tree_search_result;
        if(!right_tree_search_result) return left_tree_search_result;

        return root;


    }
};

              