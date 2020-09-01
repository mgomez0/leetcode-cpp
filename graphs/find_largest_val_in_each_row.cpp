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

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include "TreeNode.h"

class Solution {
public:
    
    std::vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> level_order_traversal;
        std::vector<int> ans;

        q.push(root);

        TreeNode* front;
        std::vector<int> level;
        while(!q.empty()){
            int size = q.size();
            level.reserve(size);
            for(int i = 0; i < size; i++){
                front = q.front();
                q.pop();
                level.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }

            }
       
            level_order_traversal.push_back(level);
            level.clear();
        }

        for (auto i: level_order_traversal){
            ans.push_back(*std::max_element(i.begin(), i.end()));

        }
        
        return ans;
    }



};


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    // root->left->left->left = new TreeNode(7);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    // root->right->right->right = new TreeNode(8);
    Solution sol;
    for(auto i: sol.largestValues(root)){
        std::cout << i;
    }
}
    