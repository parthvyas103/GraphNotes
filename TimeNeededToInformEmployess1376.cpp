class Solution {
public:
    void dfs(int curr, int &res, unordered_map<int, vector<int>> &adj, int node, vector<int> &informTime){
        curr = curr + informTime[node];
        res = max(curr, res);
        for(auto it: adj[node]){
            dfs(curr, res, adj, it, informTime);
        }
        curr = 0;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        int start;
        for(int i = 0; i < n; i++){
            adj[manager[i]].push_back(i);
            if(manager[i] == -1)
                start = i;
        }
        int curr = 0, res = 0;
        dfs(curr, res, adj, start, informTime);
        return res;
    }
};
