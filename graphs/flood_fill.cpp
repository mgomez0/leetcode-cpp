#include <vector>
#include <iostream>

class Solution {
public:
    
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, 
                                            int sr, int sc, int newColor) 
    {   
        int num_rows = image.size();
        int col = image[0].size();
        std::vector<std::vector<bool>> visited(num_rows, std::vector<bool>(col, false));
        int base_color = image[sr][sc];
        if (base_color != newColor){
            image[sr][sc] = newColor;
            dfs(image, sr, sc, base_color, newColor, visited);
        }
        return image;
        
        
    }

    void dfs(std::vector<std::vector<int>>& image, int curr_row, int curr_col,
             int base_color, int new_color, std::vector<std::vector<bool>>& visited){
        
        visited[curr_row][curr_col] = true;
        
        if(curr_row - 1 >= 0){
            if(image[curr_row-1][curr_col] == base_color &&
            visited[curr_row-1][curr_col] == false)
            {
                image[curr_row-1][curr_col] = new_color;
                dfs(image, curr_row-1, curr_col, base_color, new_color, visited);

            }
        }

        if(curr_col -1 >= 0){
            if(image[curr_row][curr_col-1] == base_color &&
            visited[curr_row][curr_col-1] == false)
            {
                image[curr_row][curr_col-1] = new_color;
                dfs(image, curr_row, curr_col-1, base_color, new_color, visited);

            }
        }

        if(curr_row + 1 < image.size()){
            if(image[curr_row+1][curr_col] == base_color &&
                visited[curr_row+1][curr_col] == false)
                {
                    image[curr_row+1][curr_col] = new_color;
                    dfs(image, curr_row+1, curr_col, base_color, new_color, visited);

                }
        }

        if(curr_col + 1 < image[curr_row].size()){
            if(image[curr_row][curr_col+1] == base_color &&
            visited[curr_row][curr_col+1] == false)
            {
                image[curr_row][curr_col+1] = new_color;
                dfs(image, curr_row, curr_col+1, base_color, new_color, visited);

            }
        }
        return;
    }
};

int main(){
    std::vector<std::vector<int>> image = {{0,0,0},{0,0,0}};
    Solution sol;
    sol.floodFill(image, 0, 0, 2);
    for (const std::vector<int> &v : image)
    {
        for(int x : v)
        {
            std::cout << x << std::endl;
        }
        
    }
}