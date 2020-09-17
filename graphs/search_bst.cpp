/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * 
 * 
 * 
 *  Runtime: 64 ms, faster than 80.59% of C++ online submissions for Search in a Binary Search Tree.
    Memory Usage: 35.1 MB, less than 5.17% of C++ online submissions for Search in a Binary Search Tree.
    Next challenges:
 * };
 */
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(root->val == val) return root;
        
        if(val < root->val){
            return searchBST(root->left, val);    
        }
        
        if(val > root->val){
            return searchBST(root->right, val);
        }
        
        return nullptr;
    }
};