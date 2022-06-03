class Solution {
public:
    int r, c;
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 or j < 0 or i >= r or j >= c or grid[i][j] != 1) return 0;
        grid[i][j] = -1;
        return 1 + dfs(grid, i+1 , j) + dfs(grid, i-1 , j) + dfs(grid, i , j+1) + dfs(grid, i , j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int count = 0, res = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 1){
                    res = max(res, dfs(grid, i, j));
                }
            }
        }
        
        return res;
    }
};
