// We are given a binary tree (with root node root), a target node, and an integer value K.

// Return a list of the values of all nodes that have a distance K from the target node.  
// The answer can be returned in any order.

#include <bits/stdc++.h>
using namespace std;
#include "TreeNode.h"
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp; // child->parent
    set<TreeNode*> visited;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {    
        queue<TreeNode*> q; // for bfs
        int curr_level = 0; // track distance from node
        //first do dfs to populate child-parent map
        dfs(root, nullptr);
        //now do bfs from target node
        q.push(target);
        vector<int> level;
        TreeNode* front;
        while(!q.empty()){
            int sz = q.size();
            level.reserve(sz);
            for(int i = 0; i < sz; i++){
                front = q.front();
                q.pop();
                if(curr_level == K){
                    for(auto i : q){
                        level.push_back(i->val);
                    }

                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                if(mp.find(front) != mp.end()){
                    q.push(mp[front]);
                }
            } curr_level++;
        }

        return level;

    }

    void dfs(TreeNode* root, TreeNode* parent){
        if(!root) return;
        if(root->left)
        mp[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(0);
    TreeNode* target = root->left;
    Solution sol;
    sol.distanceK(root, root->left, 2);
}
