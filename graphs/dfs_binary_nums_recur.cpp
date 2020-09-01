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

int ROOT_TO_LEAF = 0;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

void addLeftChild(TreeNode* node, int child_val){
    node->left =  new TreeNode(child_val);
}

void addRightChild(TreeNode *node, int child_val){
    node->right = new TreeNode(child_val);
}



class Solution {
int root_to_leaf = 0;
public: void preorder(TreeNode* root, int current_val) {
    if (root != nullptr){
        current_val = (current_val << 1) | root->val;
        if((root->left == nullptr) && (root->right== nullptr)){
           root_to_leaf += current_val;
        }
        preorder(root->left, current_val);
        preorder(root->right, current_val);
    }
}

public: int sumRootToLeaf(TreeNode *root){
    preorder(root, 0);
    return root_to_leaf;
}
};


int main(){
    TreeNode* root = new TreeNode(1); 
    root->left = new TreeNode(0); 
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);  
    root->right = new TreeNode(1); 
    root->right->left = new TreeNode(0); 
    root->right->right = new TreeNode(1); 
    std::cout << Solution::sumRootToLeaf(root);

}
