// In a given 2D binary array A, there are two islands.  
// (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

// Return the smallest number of 0s that must be flipped.
// (It is guaranteed that the answer is at least 1.)

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

class Solution {
public:
    int n;
    std::vector<int> dx = {0,0,1,-1};
    std::vector<int> dy = {1,-1,0,0};
    
    int shortestBridge(std::vector<std::vector<int>>& A)
    {
        std::set<std::pair<int, int>> island_a;
        std::set<std::pair<int, int>> island_b;
        n = A.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < A[0].size(); j++){
                if(A[i][j] == 0){
                    continue;
                }
                if(island_a.empty()){
                    floodFill(island_a, A, i,j);
                } else if(island_b.empty() && !island_a.count({i,j})){
                    floodFill(island_b, A, i,j);
                }
            }
        }
        int ans = 2*n;
        for(auto i: island_a){
            for(auto j: island_b){
                ans = std::min(ans, dist(i,j));
            }
        }
        return ans;
    }

    void floodFill(std::set<std::pair<int, int>>& island,
                   std::vector<std::vector<int>>& grid,
                   int x,
                   int y)
    {
        island.insert({x,y});
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
    
    template<class T>
    int dist(T a, T b){
        return abs(a.first - b.first) + abs(a.second - b.second) - 1;
    }


};