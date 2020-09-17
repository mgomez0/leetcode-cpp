#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int path_sum = 0;
    int sr = 0;
    int sc = 0;
    int dr = -1;
    int dc = 1;
    
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        visited.reserve(rows);
        for (auto i : visited){
            i.reserve(cols);
        }
          
        queue<int> rq;
        queue<int> cq;
        rq.push(sr);
        cq.push(sc);

        while(!rq.empty()){
            int r = rq.front();
            rq.pop();
            int c = cq.front();
            cq.pop();
            if(r == rows-1 &&  c == cols-1){
                break;
            }
            explore_neighbors(r,c);

        }
    }

    void explore_neighbors(int r, int c){
        if(r + dr < 0 || c + dc < 0) return;
        if(r + dr >= r || c + dc >= c) return;
        if(visited[r+dr][c+dc] == )

    }
};