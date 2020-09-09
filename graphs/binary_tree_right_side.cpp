// Given a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

#include "TreeNode.h"
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        queue<TreeNode*> q;
        vector<vector<int>> level_order_traversal;
        vector<int> level;

        TreeNode* front;
        q.push(root);
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

        for (auto i : level_order_traversal){
            result.push_back(i[i.size()-1]);
        }

        return result;
    }
};