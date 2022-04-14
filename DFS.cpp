void dfs(vector<int> adj[], vector<int> &res, vector<bool> &visited, int v){
        if(visited[v])
            return;
        visited[v] = true;
        res.push_back(v);
        for(auto x : adj[v]){
            dfs(adj, res, visited, x);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        vector<bool> visited(V, 0);
        dfs(adj, res, visited, 0);
        return res;
    }
