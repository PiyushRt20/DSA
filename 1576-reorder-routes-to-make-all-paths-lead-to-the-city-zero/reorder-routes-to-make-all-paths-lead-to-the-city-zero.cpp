class Solution {
public:
    void dfs(int node, vector<vector<pair<int,int>>>&adj, vector<int>&vis, int& ans){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                ans += it.second;
                dfs(it.first, adj, vis, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        vector<int> vis(n, 0);
        int ans = 0;
        dfs(0, adj, vis, ans);
        return ans;
    }
};