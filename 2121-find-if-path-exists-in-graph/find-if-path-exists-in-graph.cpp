class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(source, vis, adj);
        return vis[destination] == 1 ? true : false;
    }
};