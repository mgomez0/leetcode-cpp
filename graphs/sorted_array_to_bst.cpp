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
 * 
 *  Given an array where elements are sorted in ascending order, convert it to a 
 *  height balanced BST.
    For this problem, a height-balanced binary tree is defined as a binary tree in which
    the depth of the two subtrees of every node never differ by more than 1.
 */
#include "TreeNode.h"
#include <vector>
class Solution {
public:

    TreeNode* helper(std::vector<int>& nums, int begin, int end){
        if(begin > end)
            return nullptr;
        TreeNode* root = new TreeNode();
        int mid = begin + (end - begin)/2;
        root->setVal(nums[mid]);
        root->setLeftChild(helper(nums, begin, mid-1));
        root->setRightChild(helper(nums, mid+1, end));
        return root;
    }
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        helper(nums, 0, nums.size()-1);
    }
};