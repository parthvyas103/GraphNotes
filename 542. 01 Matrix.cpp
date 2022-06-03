class Solution {
public:
    int m, n;
    bool isvalid(int i,int j)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> dis(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            for(auto x: dir){
                int a = x[0] + curr.first;
                int b = x[1] + curr.second;
                if(isvalid(a, b) && dis[a][b] == -1){
                    dis[a][b] = 1 + dis[curr.first][curr.second];
                    q.push({a, b});
                }
            }
        }
        
        return dis;
    }
};
