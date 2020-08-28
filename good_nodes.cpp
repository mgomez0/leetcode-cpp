// Given a binary tree root, a node X in the tree is named 
// good if in the path from root to X there are no nodes with a value greater than X.
//
// Success
// Details 
// Runtime: 516 ms, faster than 5.19% of C++ online submissions for Count Good Nodes in Binary Tree.
// Memory Usage: 272.6 MB, less than 5.09% of C++ online submissions for Count Good Nodes in Binary Tree.
// Return the number of good nodes in the binary tree.

#include "TreeNode.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
class Solution {
public:
    int num_good;
    int goodNodes(TreeNode* root) {
        std::vector<int> path_vector;
        dfs(root, path_vector);
        return num_good;
    }

    void dfs(TreeNode* root, std::vector<int> path_vector){
        if(!root){return;}
        
        int max_val = INT_MIN;
        
        if(!path_vector.empty()){
            max_val = *std::max_element(path_vector.begin(), path_vector.end());
        }

        path_vector.push_back(root->val);
        if (root->val >= max_val){
            num_good++;
        }

        if(root->left){
            dfs(root->left, path_vector);
        }

        if(root->right){
            dfs(root->right, path_vector);
        }
    }
};


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);  
    root->left->left = new TreeNode(3);

    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    std::cout << sol.goodNodes(root);
}