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
Given the root node of a binary search tree (BST) and a value to be inserted 
into the tree, insert the value into the BST. Return the root node of the BST 
after the insertion. It is guaranteed that the new value does not exist in the
original BST.

Note that there may exist multiple valid ways for the insertion, 
as long as the tree remains a BST after insertion. 
You can return any of them.

For example, 


 */
#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {   
        if(!root)
        {
            TreeNode* new_root = new TreeNode(val);
            return new_root;
        }  
        
        dfs(root, val);
        return root;
    }

    void dfs(TreeNode* root, int val)
    {
        if(!root) return;

        if(!root->left || !root->right)
        {
            TreeNode* add = new TreeNode(val);
            
            if(!root->left && val < root->val )
            {
                
                root->left = add;
            }

            if(!root->right && val > root->val)
            {
                
                root->right = add;
            }
        }

        if(root->left && val < root->val)
        {
            dfs(root->left, val);
        }

        if(root->right && val > root->val)
        {
            dfs(root->right, val);
        }
    }
};