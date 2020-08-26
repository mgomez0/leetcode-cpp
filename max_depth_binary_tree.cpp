/**
 * Runtime: 20 ms, faster than 26.16% of C++ online submissions for Maximum Depth of Binary Tree.
    Memory Usage: 19.2 MB, less than 65.24% of C++ online submissions for Maximum Depth of Binary Tree.
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
#include <algorithm>
#include <iostream>
class Solution {
int max_depth = 0;
public:
    void dfs(TreeNode* root, int current_depth) {
            if(root != nullptr){
                current_depth++;
                if((root->getLeftChild() == nullptr) && (root->getRightChild()== nullptr) && (current_depth > max_depth)){
                   max_depth = current_depth;
                }
                dfs(root->getLeftChild(), current_depth);
                dfs(root->getRightChild(), current_depth);
                
            }
    };
public:
    int maxDepth(TreeNode* root){
        dfs(root, 0);
        return max_depth;
    }
};

int main(){
    TreeNode *root_left_ptr = new TreeNode(9);
    TreeNode *root_right_ptr = new TreeNode(20);
    TreeNode *root_right_left_ptr = new TreeNode(15);
    TreeNode *root_right_right_ptr = new TreeNode(7);
    TreeNode *root_ptr = new TreeNode(3, root_left_ptr, root_right_ptr);
    root_right_ptr->setRightChild(root_right_right_ptr);
    root_right_ptr->setLeftChild(root_right_left_ptr);
    Solution sol;
    std::cout << sol.maxDepth(root_ptr) << std::endl;
    

}