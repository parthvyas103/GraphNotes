void dfs(vector<vector<int>> adj, int V, int x, vector<int> &visited){
        visited[x] = 1;
        
        for(int i = 0; i < V; i++){
            if(adj[x][i] == 1 && !visited[i])
                dfs(adj, V, i, visited);
        }
        
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> visited(V, 0);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(adj, V,i, visited);
                count++;
        }
        }
        
        return count;
    }
