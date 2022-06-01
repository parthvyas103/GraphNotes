class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1)
            return;
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        grid[i][j] = '2';
        
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ++res;
                }
            }
        }
        
        return res;
    }
};
