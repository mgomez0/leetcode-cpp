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

#include <queue>
#include <vector>
#include "TreeNode.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if(!root){return{};}
        std::queue<TreeNode*> nodes;
        std::vector<std::vector<int>> ans;
        nodes.push(root);
        
        std::vector<int> level;
        TreeNode* front;
        while(!nodes.empty()){
            int size = nodes.size();
            level.reserve(size);
            for(int i = 0; i < size; i++){
                front = nodes.front();
                nodes.pop();
                level.push_back(front->val);
                if(front->left != nullptr){
                    nodes.push(front->left);
                }                
                if(front->right != nullptr){
                    nodes.push(front->right);
                }                
            }
            ans.push_back(level);
            level.clear();
        } 
        
        return ans;
    
    }
};