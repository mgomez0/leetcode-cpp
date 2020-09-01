// Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a 
// binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, 
// then this could represent 01101 in binary, which is 13.

// For all leaves in the tree, consider the numbers represented by the path from the root to 
// that leaf.

// Return the sum of these numbers.


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



int sumRootToLeaf(TreeNode* root) {
    std::vector< std::pair<TreeNode*, int> > node_stack;
    node_stack.push_back(std::make_pair(root,0));
    int root_to_leaf = 0;
    int current_val;
    while (!node_stack.empty()){
        root = std::get<0>(node_stack.back());
        current_val = std::get<1>(node_stack.back());
        node_stack.pop_back();
        if (root != nullptr){
            current_val = (current_val << 1) | root->val;
            if ((root->left == nullptr) & (root->right == nullptr)){
                root_to_leaf += current_val;
            } else{
                node_stack.push_back(std::make_pair(root->right, current_val));
                node_stack.push_back(std::make_pair(root->left, current_val));
            }
        }
    
    }
    return root_to_leaf;
}

int main(){
    TreeNode* root = new TreeNode(1); 
    root->left = new TreeNode(0); 
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);  
    root->right = new TreeNode(1); 
    root->right->left = new TreeNode(0); 
    root->right->right = new TreeNode(1); 
    std::cout << sumRootToLeaf(root);

}
