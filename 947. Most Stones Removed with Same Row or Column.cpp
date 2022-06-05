class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    
    int find(int x){
        return parent[x] == x ? x : find(parent[x]);
    }
    
    bool onion(int n1, int n2){
        int p1 = find(n1); int p2 = find(n2);
        if(p1 == p2)
            return false;
        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p2] == rank[p1]){      
            parent[p1] = p2;
        }
        else{
            rank[p1]++;
            parent[p2] = p1;
        }
        return true;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        rank.resize(n, 0);
        parent.resize(n, 0);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        int count = n;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    if(onion(i, j))
                        count--;
                }
            }
        }
        
        
        return n-count;
    }
};
