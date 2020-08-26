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
 * Given a binary tree, return all root-to-leaf paths.

    Note: A leaf is a node with no children.

    Example:

    Input:

    1
    /   \
    2     3
    \
    5

    Output: ["1->2->5", "1->3"]

    Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 */
#include <vector>
#include <iostream>
#include <string>
#include "TreeNode.h"

class Solution {
public:
    
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::string path;
        std::vector<std::string> path_vector;
        dfs(root, path_vector, path);
        return path_vector;
    }
    
    void dfs(TreeNode* root, std::vector<std::string> &path_vector,
             std::string path){
                if(!root){return;}        

                if(root->left || root->right){
                    path.append(std::to_string(root->val)+"->");
                }

                if(root->left == nullptr &&
                root->right == nullptr){
                    path.append(std::to_string(root->val));
                    path_vector.push_back(path);        
                }
                dfs(root->left, path_vector, path);
                dfs(root->right, path_vector, path);
            }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    Solution sol;
    for(auto i : sol.binaryTreePaths(root)){
        std::cout << i << std::endl;
    }
}