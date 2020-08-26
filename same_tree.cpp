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
#include <stdio.h>
#include <iostream>
#include <utility>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr){ return true; }
        if(p == nullptr || q == nullptr){ return false;}
        if(p->val != q->val)            { return false;}
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

};


int main(){
    TreeNode* p = new TreeNode(1); 
    TreeNode* q = new TreeNode(1); 
    p->left = new TreeNode(2);  
    q->right = new TreeNode(2);
    Solution sol;
    std::cout << sol.isSameTree(p,q);
}