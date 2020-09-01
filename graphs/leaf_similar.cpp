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
#include <iostream>
#include "TreeNode.h"

class Solution {
bool result = false;
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> r1_leaf_list;
        std::vector<int> r2_leaf_list;
        dfs(root1, r1_leaf_list);
        dfs(root2, r2_leaf_list);
        return r1_leaf_list == r2_leaf_list;
    }
    
    void dfs(TreeNode* r, std::vector<int>& leaf_list)
            {
                if(r == nullptr)
                    return;
                if
                (
                    r->left == nullptr &&
                    r->right == nullptr
                )
                {   
                    leaf_list.push_back(r->val);
                }
                     
                if(r->left != nullptr)
                    dfs(r->left, leaf_list);
                
                if(r->right != nullptr)
                    dfs(r->right, leaf_list);   
    }
};

int main(){
    TreeNode* root1 = new TreeNode(1); 
    TreeNode* root2 = new TreeNode(2); 
    
    Solution sol;
    std::cout << sol.leafSimilar(root1, root2);
}