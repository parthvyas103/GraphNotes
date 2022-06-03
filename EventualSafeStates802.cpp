class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &color, int node){
        color[node] = 1;
        
        for(auto x: graph[node]){
            if(color[x] == 0){
                if(dfs(graph, color, x)){
                    color[x] = 3;
                    return true;
                }
            }
            else if(color[x] != 2){
                color[x] = 3;
                return true;
            }
        }
        
        color[node] = 2;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, 0);
        
        for(int i = 0; i < V; i++){
            if(color[i] == 0)
                dfs(graph, color ,i);
        }
        
        vector<int> res;
        for(int i = 0; i < V; i++)
            if(color[i] == 2)
                res.push_back(i);
        return res;
    }
};
