/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

Given a binary tree containing digits from 0-9 only, 
each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
Note: A leaf is a node with no children.

 * 
 * 
 * 
 * 
 *  };
 */

#include "TreeNode.h"
#include<bits/stdc++.h>
using namespace std;
class Solution {
vector<vector<int>> path_collection;
vector<int> path;
public:
    int sumNumbers(TreeNode* root) {
        
        dfs(root);
    }

    void dfs(TreeNode* root){
        if(!root) return;

        if(!root->left && !root->right)
        {
            path.push_back(root->val
        }
    }
};