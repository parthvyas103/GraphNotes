bool dfs(int node, int vis[], int dfsvis[], vector<int> adj[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto x: adj[node]){
            if(!vis[x]){
                if(dfs(x, vis, dfsvis, adj))
                    return true;
            }
            else if(dfsvis[x])
                return true;
        }
        
        dfsvis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V];
        int dfsvis[V];
        memset(vis, 0, sizeof vis);
        memset(dfsvis, 0, sizeof dfsvis);
        
        for(int i = 0; i < V; i++){
            if(!vis[i])
                if(dfs(i, vis, dfsvis, adj))
                    return true;
        }
        
        return false;
    }
