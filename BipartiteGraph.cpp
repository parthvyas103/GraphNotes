bool bipartite(vector<vector<int>>& graph, int V, vector<int> &color, int src){
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto x: graph[node]){
                if(color[x] == -1){
                    color[x] = 1 - color[node];
                    q.push(x);
                }
                else if(color[x] == color[node])
                    return false;;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++){
            if(color[i] == -1)
            if(!bipartite(graph, V, color, i))
                return false;
        }
        return true;
    }
