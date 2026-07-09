class DisjointSet{
    vector<int>parent, size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_UP(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find_UP(parent[node]);
    }
    void unionBySize(int u, int v){
        int UP_U = find_UP(u);
        int UP_V = find_UP(v);
        if(UP_U == UP_V) return;
        if(size[UP_U] < size[UP_V]){
            parent[UP_U] = UP_V;
            size[UP_V] += size[UP_U];
        }
        else{
            parent[UP_V] = UP_U;
            size[UP_U] += size[UP_V];
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i=1; i<n; i++){
            if(abs(nums[i] - nums[i-1]) <= maxDiff){
                ds.unionBySize(i-1, i);
            }
        }
        int q = queries.size();
        vector<bool> ans(q, false);
        for(int i=0; i<q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(ds.find_UP(l) == ds.find_UP(r)){
                ans[i] = true;
            }
        }
        return ans;
    }
};