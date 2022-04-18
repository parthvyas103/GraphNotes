//https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/

void dfs(vector<vector<int>> adj, vector<bool> &visited, int n, int node){
        if(visited[node])
            return;
        visited[node] = true;
        for(auto x : adj[node])
            if(!visited[x])
                dfs(adj, visited, n, x);
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        vector<vector<int>> adj(n);
        
        for(auto x : connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int res = 0;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; i++){
            if(!visited[]){
                dfs(adj, visited, n, i);
                res++;
            }
        } 
        return res-1;
    }
