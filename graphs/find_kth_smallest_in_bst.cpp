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
Next challenges:
Second Minimum Node In a Binary Tree
Show off your acceptance:
Time Submitted
Status
Runtime
Memory
Language
09/14/2020 15:34	Accepted	36 ms	24.3 MB	cpp


 * 
 *  };
 */
#include<bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution {
public:
    int res = 0;
    int kthSmallest(TreeNode* root, int k) 
    {
        dfs(root, k);
        return res;
    }
    
    void dfs(TreeNode* root,int& k)
    {
        if(!root) return;
        dfs(root->left, k);
        k--;
        if(k == 0){
            res = root->val;
        }
        dfs(root->right, k);
        
    }
};