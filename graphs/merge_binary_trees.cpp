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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    TreeNode* result;
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        
        if(!t1 && !t2) return nullptr;
        if(!t1) return t2;
        if(!t2) return t1;
        TreeNode* root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        return root;
    
    }
};


int main(){
    TreeNode* p = new TreeNode(1); 
    TreeNode* q = new TreeNode(2); 
    p->left = new TreeNode(3);  
    p->right = new TreeNode(2);
    p->left->left = new TreeNode(5); 
    q->right = new TreeNode(3);
    q->left = new TreeNode(1);
    q->left->right = new TreeNode(4);
    q->right->right = new TreeNode(7);
    Solution sol;
    std::cout << sol.mergeTrees(p,q);
}