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
#include <queue>
#include <vector>
#include <iostream>

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::vector<std::vector<int>> level_order_traversal;
        std::vector<int> level;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        TreeNode* front;

        while(!nodes.empty()){
            int size = nodes.size();
            level.reserve(size);
            for(int i = 0; i < size; i++){
                front = nodes.front();
                level.push_back(front->val);
                nodes.pop();
                if(front->left){
                    nodes.push(front->left);
                }
                if(front->right){
                    nodes.push(front->right);
                }
            }
            level_order_traversal.push_back(level);
            level.clear();
        }

        return level_order_traversal.back()[0];
    }

};

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);  
    root->right = new TreeNode(3);
 
    

    Solution sol;
    std::cout << sol.findBottomLeftValue(root);
}