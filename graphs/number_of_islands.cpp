// start at 0,0
// loop until you find a 1
// do a flood fill
// when you're out of 1s, continue loop
// flood fill when you find another one
// so on and so forth
// count number of groups

#include <bits/stdc++.h>
using namespace std;


class UnionFind{
    private:

        //number of elements in union find
        int size;
        
        //used to track the sizes of each of the components
        int sz[];

        // id[i] points to parent of i, if id[i] = i then i is a root node
        int id[];

        // tracks the number of components in the union find
        int num_components;

    public:
        UnionFind(int size){
            UnionFind::this.size = numComponents = size;

        }
}
class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        
    }
    
};