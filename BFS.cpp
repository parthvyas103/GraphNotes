vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> visited(V, 0);
        q.push(0);
        vector<int> res;
        res.push_back(0);
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto x: adj[p]){
                if(visited[x]) continue;
                visited[x] = 1;
                res.push_back(x);
                q.push(x);
            }
        }
        return res;
    }
