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
        if(node == par[node]){
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        //agr kisi node ki indegree 2 h toh dsu krte hue use include mt krna pahale
        vector<int> indegree(n+1, 0);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            indegree[v]++;
        }
        int node = 0;
        for(int i =1; i<=n; i++){
            if(indegree[i] == 2){
                node = i;
            }
        }
        DisjointSet ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(v == node) continue;                         //include nhi kr rha
            if(ds.find_UP(u) == ds.find_UP(v)){
                return {u, v};
            }
            ds.unionBySize(u, v);
        }
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(v != node) continue;
            if(ds.find_UP(u) == ds.find_UP(v)){
                return {u, v};
            }
            ds.unionBySize(u, v);
        }
        return {};
    }
};