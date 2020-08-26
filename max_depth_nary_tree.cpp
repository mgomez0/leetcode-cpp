#include "Node.h"
#include <vector>
#include <iostream>
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// }

class Solution {
int max_depth = 0;
public:
    int maxDepth(Node* root){
        dfs(root,0);
        return max_depth;
        
    }
    
    void dfs(Node* root, int curr_depth) {
        if (root == nullptr){
            return;
        }
        curr_depth += 1;
        if (root->children.empty()){
            if(curr_depth > max_depth){
                max_depth = curr_depth;
            }
        } else{
            for(auto i : root->children){
                dfs(i, curr_depth);
            }
        }
        
    }
};

int main(){
    std::vector<Node*> root_children = {new Node(3),new Node(2),new Node(4)};
    std::vector<Node*> three_children = {new Node(5),new Node(6)};
    Node* root = new Node(1, root_children);
    root->children[0]->children = three_children;
    Solution sol;
    std::cout << sol.maxDepth(root);
}