// Given a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

#include "TreeNode.h"
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> result;
    vector<int> rightSideView(TreeNode* root) {
        if(!root){return {};}      
        dfs(root);
        return result;
    }

    void dfs(TreeNode* root){
        result.push_back(root->val);
        if(root->right){
            dfs(root->right);
        }
    }

};