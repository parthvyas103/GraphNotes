vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        q.push({0, S});
        while(!q.empty()){
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            for(auto it: adj[node]){
                int nextdis = it[1];
                int next = it[0];
                if(dis + nextdis < dist[next]){
                    dist[next] = dis + nextdis;
                q.push({dist[next], next});
                }
            }
        }
        
        return dist;
    }
