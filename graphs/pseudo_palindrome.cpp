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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> curr_path;
    vector<vector<int>> paths;
    int pseudoPalindromicPaths (TreeNode* root) {
        int ctr = 0;
        dfs(root);
        for(auto it = paths.begin(); it != paths.end(); ++it){
            sort(it->begin(), it->end());
        }
        
        for(auto i: paths){
            do{
                int* start = &i.front();
                int* end = &i.back();
                int path_size = i.size()/2;
                while(path_size>0){
                    if(*start == *end){
                        start++;
                        end--;
                        path_size--;
                    } else{
                        break;
                    } ctr++;
                }
            } 
            while(next_permutation(i.begin(), i.end()));
        } return ctr;
    }

    void dfs(TreeNode* root){
        if(!root)
        {
            return;
        }

        if(!root->left && !root->right){
            curr_path.push_back(root->val);
            paths.push_back(curr_path);
            curr_path.pop_back();
            return;
        }
        
        curr_path.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        curr_path.pop_back();
        
       
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(1);
    
    cout << sol.pseudoPalindromicPaths(root);
}