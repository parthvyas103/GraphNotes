class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int node){
        if(visited[node]) return;
        visited[node] = true;
        
        for(auto x: rooms[node]){
            if(!visited[x])
                dfs(rooms, visited, x);
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        dfs(rooms, visited, 0);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == false)
                return false;
        }
        
        return true;
    }
};
