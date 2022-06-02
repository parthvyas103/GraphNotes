class Solution {
public:
    int r, c;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 or j<0 or i >= r or j >= c or grid[i][j] != 0) return;
        grid[i][j] = -1;
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        r= grid.size();
        c = grid[0].size();
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if((i == 0 || j == 0 || i == r-1 || j == c-1) && grid[i][j] == 0)
                    dfs(grid, i, j);
            }
        }
        
        int res = 0;
        for(int i =0; i < r; i++){
            for(int j =0; j < c; j++){
                if(grid[i][j] == 0){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
};
