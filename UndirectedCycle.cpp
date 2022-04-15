bool cycleCheck(int node, vector<int> adj[], vector<int> &visited, int V){
        queue<pair<int, int>> q;
        q.push({node, -1});
        
        visited[node] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto x: adj[node]){
                if(!visited[x]){
                    visited[x] = 1;
                    q.push({x, node});
                }
                else if(x != par)
                    return true;
            }
        }
        
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!visited[i])
                if(cycleCheck(i, adj, visited, V))
                    return true;
        }
        
        return false;
    }
