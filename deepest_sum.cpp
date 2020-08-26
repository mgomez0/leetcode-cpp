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

 Given a binary tree, return the sum of values of its deepest leaves.
 */

#include "TreeNode.h"
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> level_order_vector;
    
    int deepestLeavesSum(TreeNode* root) {   
       int result = 0;
       std::vector<int> deep_vector;
       level_order(root);
       deep_vector = level_order_vector.back();
       for(auto it = deep_vector.begin(); it != deep_vector.end(); ++it){
           result += *it;
       }
       return result;
    }

    void level_order(TreeNode* root){
        if(!root){return;}

        std::vector<int> curr_level;
        std::queue<TreeNode*> nodes;
        TreeNode* front;
        nodes.push(root);

        while(!nodes.empty()){
            int size = nodes.size();
            curr_level.reserve(size);
            for(int i = 0; i < size; i++){
                front = nodes.front();
                curr_level.push_back(front->val);
                nodes.pop();
                if(front->left){
                    nodes.push(front->left);
                }       
                if(front->right){
                    nodes.push(front->right);
                }
            }

            level_order_vector.push_back(curr_level);
            curr_level.clear();
        }

        return;
    }

};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(7);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(8);
    Solution sol;
    sol.deepestLeavesSum(root);
}