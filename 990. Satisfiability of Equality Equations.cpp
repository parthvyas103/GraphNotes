class Solution {
public:
    int parent[1001];
    int find(int x){
        return parent[x] == x ? x : find(parent[x]);
    }
    
    void onion(int x, int y){
        if(x > y)
            swap(x, y);
        int p1 = find(x); int p2 = find(y);
        parent[p1] = p2;
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i < 26; i++)
            parent[i] = i;
        
        for(auto x: equations){
            int a = x[0] - 'a';
            int b = x[3] - 'a';
            if(x[1] == '=')
                onion(a, b);
        }
        
        for(auto x: equations){
            int a = x[0] - 'a';
            int b = x[3] - 'a';
            if(x[1] == '!' && find(a) == find(b))
                return false;
        }
        
        return true;
    }
};
