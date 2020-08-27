//  Success
// Details 
// Runtime: 24 ms, faster than 43.20% of C++ online submissions for Path Sum II.
// Memory Usage: 34 MB, less than 38.44% of C++ online submissions for Path Sum II.
// Given a binary tree and a sum, find all root-to-leaf paths where each 
// path's sum equals the given sum.

// Note: A leaf is a node with no children.

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
#include<vector>
#include "TreeNode.h"
class Solution {
public:
    std::vector<std::vector<int>> solution;
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<int> path;
        int path_sum = 0;
        dfs(root,sum, path, path_sum);
        return solution;
    }

    void dfs(TreeNode* root, int sum, std::vector<int> path, int path_sum){
        if(!root){return;}
        path.push_back(root->val);
        path_sum += root->val;
        
        if(root->left){
            dfs(root->left, sum, path, path_sum);
        }
        if(root->right){
            dfs(root->right, sum, path, path_sum);
        }
        if(!root->left&&
           !root->right){
            if(path_sum == sum){
                solution.push_back(path);
            }
        }
    }
};