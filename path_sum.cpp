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

class Solution {
public:
    bool exists = false;
    bool hasPathSum(TreeNode* root, int sum) {
        dfs(root, sum, 0);
        return exists;
    }
    
    void dfs(TreeNode* root,int sum,int path_sum){
        if(root == nullptr){
            return;
        }
        
        path_sum += root->val;
        if(root->left == nullptr &&
           root->right == nullptr){
            if(path_sum == sum){
                exists = true;
                return;
            }
        }
        if(root->left != nullptr){
            dfs(root->left, sum ,path_sum);
        }
        if(root->right != nullptr){
            dfs(root->right, sum ,path_sum);
        }
    }
};