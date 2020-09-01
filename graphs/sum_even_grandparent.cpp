// Given a binary tree, return the sum of values of nodes with even-valued grandparent.
// (A grandparent of a node is the parent of its parent, if it exists.)

// If there are no nodes with an even-valued grandparent, return 0.

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
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<TreeNode*> even_grandparent;
    int sumEvenGrandparent(TreeNode* root) {
        vector<TreeNode*> prev_nodes;
        int final_sum = 0;
        dfs(root, prev_nodes, 0);
        for (auto i: even_grandparent){
            final_sum += i->val;
        }

        return final_sum;
    }

    void dfs(TreeNode* root, vector<TreeNode*> prev_nodes, int curr_level){
        if(!root){return;}
        prev_nodes.push_back(root);
        
        
        TreeNode* grandparent;
        if(curr_level >= 2){
            if((prev_nodes[curr_level - 2])->val % 2 == 0){
                even_grandparent.push_back(root);
            }
        }
        if(root->left){
            dfs(root->left, prev_nodes, curr_level+1);
        }
        if(root->right){
            dfs(root->right, prev_nodes, curr_level+1);
        }
        
        prev_nodes.pop_back();

    }
};


int main(){
    TreeNode* root = new TreeNode(6); 
    root->left = new TreeNode(7); 
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(9);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(4);
    
    root->right = new TreeNode(8); 
    root->right->left = new TreeNode(1); 
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(5);  
    Solution sol;
    cout << sol.sumEvenGrandparent(root);
}