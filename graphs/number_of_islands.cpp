// start at 0,0
// loop until you find a 1
// do a flood fill
// when you're out of 1s, continue loop
// flood fill when you find another one
// so on and so forth
// count number of groups

#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int n;
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};
    int numIslands(vector<vector<char>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();

        for(int i = 0; i < num_rows; i++){
            for(int j = 0; j < num_cols; j++){
                if(grid[i][j]){
                    floodFill(grid,i,j);
                }
            }
        }
    }

    void floodFill(vector<vector<int>>& grid,
                   int x,
                   int y)
    {
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx,ny) && grid[nx][ny] && !island.count({nx,ny})){
                floodFill(island, grid, nx, ny);
            }
        }    

    }

    bool isValid(int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    
};