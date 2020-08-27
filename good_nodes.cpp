// Given a binary tree root, a node X in the tree is named 
// good if in the path from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.

#include "TreeNode.h"
#include <vector>
#include <algorithm>
class Solution {
public:
    int num_good;
    int goodNodes(TreeNode* root) {
        std::vector<int> path_vector;
        dfs(root, path_vector);
    }

    void dfs(TreeNode* root, std::vector<int> path_vector){
        if(!root){return;}
        path_vector.push_back(root->val);
        for(int i : path_vector){
            if(i > *std::max_element(path_vector.begin(), path_vector.end())){
                
            }
        }


    }
};