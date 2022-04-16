//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/

void dfs(int x, int y, vector<vector<int>> &m, vector<string> &res, string curr, int n){
        
        if(x < 0 || y < 0 || x > n-1 || y > n-1 || m[x][y] == 0)
            return;
        if(x == n-1 && y == n-1){
            res.push_back(curr);
            return;
        }
        m[x][y] = 0;
        dfs(x+1, y, m, res, curr+"D", n);
        dfs(x-1, y, m, res, curr+"U", n);
        dfs(x, y+1, m, res, curr+"R", n);
        dfs(x, y-1, m, res, curr+"L", n);
        m[x][y]  = 1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        if(m[0][0] == 0 || m[n-1][n-1] == 0)
            return res;
        dfs(0, 0, m, res, "", n);
        return res;
    }
