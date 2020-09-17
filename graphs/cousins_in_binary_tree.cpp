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
 * 
 * 
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.
 */
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(root->left || root->right) return false;
        
    }
};