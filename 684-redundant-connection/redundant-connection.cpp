class DisjointSet{
    vector<int>par, size;
public:
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1);
        for(int i =0; i<=n; i++){
            par[i] = i;
            size[i] = 1;
        }
    }    
    int find_UP(int node){
        if(par[node] == node){
            return node;
        }
        return par[node] = find_UP(par[node]);
    }
    void unionBySize(int u, int v){
        int UP_U = find_UP(u);
        int UP_V = find_UP(v);
        if(UP_U == UP_V) return;
        if(size[UP_U] < size[UP_V]){
            par[UP_U] = UP_V;
            size[UP_V] += size[UP_U];
        }
        else{
            par[UP_V] = UP_U;
            size[UP_U] += size[UP_V];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(ds.find_UP(u) == ds.find_UP(v)){
                return {u, v};
            }
            ds.unionBySize(u, v);
        }
        return {};
    }
};