class Solution {
public:
    int r, c;
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i < 0 or i >= r or j < 0 or j >= c or grid[i][j] != 1)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //start bfs from rotten
        r = grid.size(); c = grid[0].size();
        queue<pair<int, int>> q;
        
        int res = 0;
        int fresh = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        while(!q.empty() && fresh){
            int size = q.size();
            
            while(size--){
                pair<int, int> x = q.front();
                int i = x.first;
                int j = x.second;
                q.pop();
                if(isValid(i+1, j, grid)){
                    q.push({i+1, j});
                    grid[i+1][j] = 2;
                    fresh--;
                }
                if(isValid(i-1, j,grid)){
                    q.push({i-1, j});
                    grid[i-1][j] = 2;
                    fresh--;
                }
                if(isValid(i, j+1, grid)){
                    q.push({i, j+1});
                    grid[i][j+1] = 2;
                    fresh--;
                }
                if(isValid(i, j-1,grid)){
                    q.push({i, j-1});
                    grid[i][j-1] = 2;
                    fresh--;
                }
            }
            ++res;
        }
        return fresh == 0 ? res : -1;
    }
};
