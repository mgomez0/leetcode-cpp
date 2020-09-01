#include "TreeNode.h"

class Solution {    
    public:
        int minDepth(TreeNode* root){
            if(root == nullptr){
                    return 0;
                }

                if( (root->left == nullptr) && 
                    (root->right == nullptr) )    
                {
                    return 1;
                }

                int ans1 = __INT_MAX__, ans2 = __INT_MAX__;
                if(root->left != nullptr){
                    ans1= 1+minDepth(root->left);
                }
                
                if(root->left != nullptr){
                    ans1= 1+minDepth(root->right);
                }

                return (ans2 < ans1) ? ans2: ans1


};


int main(){
    TreeNode* root = new TreeNode(3); 
    root->left = new TreeNode(9); 
    // root->left->left = new TreeNode(11);
    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(20); 
    root->right->left = new TreeNode(15); 
    root->right->right = new TreeNode(7);
    // root->right->right->right = new TreeNode(1);  
    Solution sol;
    std::cout << sol.minDepth(root);
}