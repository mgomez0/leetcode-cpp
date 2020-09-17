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
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then 
 * right to left for the next level and alternate between).

    For example:
    Given binary tree [3,9,20,null,null,15,7],
        3
    / \
    9  20
        /  \
    15   7
    return its zigzag level order traversal as:
    [
    [3],
    [20,9],
    [15,7]
    ]
 */

#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        int curr_level = 0;
        deque<TreeNode*> dq;
        vector<vector<int>> result;
        vector<int> level;
        TreeNode* front;

        dq.push_back(root);

        
        while(!dq.empty())
        {
            int sz = dq.size();
            level.reserve(sz);
            for(int i = 0; i < sz; i++)
            {
                front = dq.front();
                dq.pop_front();
                level.push_back(front->val);
                if(front->left)
                {   
                    if(curr_level % 2 == 0)
                    {    
                    dq.push_front(front->left);
                    } else{
                        dq.push_back(front->left);
                    }
                }
                if(front->right)
                {
                    if(curr_level % 2 == 0)
                    {    
                    dq.push_front(front->right);
                    } else{
                        dq.push_back(front->right);
                    }       
                }
            }

            result.push_back(level);
            level.clear();
            curr_level++;
        } 

        return result;

    }
};