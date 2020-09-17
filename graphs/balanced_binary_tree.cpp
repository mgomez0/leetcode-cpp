#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool result = false;
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
        
        
    }
    
    bool dfs(TreeNode* root, int &height){
        if(!root)
        {
            height = 0;
            return true;
        }
        int height_left_tree = 0;
        int height_right_tree = 0;
        if(!dfs(root->left, height_left_tree)) return false;
        if(!dfs(root->right, height_right_tree)) return false;
        if(abs(height_left_tree - height_right_tree) > 1) return false;
        height = max(height_left_tree, height_right_tree) + 1;
        return true;
        
    }
};


int main(){
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    sol.isBalanced(root);
}