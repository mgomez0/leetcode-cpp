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
int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root, L, R);
        return sum;
    }

    void dfs(TreeNode* root, const int L, const int R){
        if(!root) return;
        if(root->val >= L && root->val <= R)
        {
            sum+=root->val;
        }
        dfs(root->left, L, R);
        dfs(root->right, L, R);

    }
};


int main(){
    Solution sol;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(18);
    cout << sol.rangeSumBST(root, 7, 15);
}