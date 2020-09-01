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
#include <vector>
#include <queue>

class Solution {
public:
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        std::queue<int> q;
        
        //convert preorder traversal to queue (DFS)
        for(auto it = preorder.begin(); it != preorder.end(); it++){
            q.push(*it);
        }                       


        TreeNode* root = new TreeNode(q.front());
        q.pop();


        // need to come back to this one
        // can be solved with monotonically decreasing stack
        // or recursively



    }
};