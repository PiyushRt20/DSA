class Solution {
public:
    void dfs(int node, int& noOfNodes, int& noOfEdges, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        noOfNodes++;
        noOfEdges += adj[node].size();
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it, noOfNodes, noOfEdges, adj, vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int> vis(n, 0);
        for(int i =0; i<n; i++){
            int noOfNodes = 0;
            int noOfEdges = 0;
            if(vis[i] == 0){
                dfs(i, noOfNodes, noOfEdges, adj, vis);
                noOfEdges /= 2;
                if(noOfEdges == noOfNodes * (noOfNodes-1)/2){
                    cnt++;
                }
                cout<<noOfNodes<<" ";
                cout<<noOfEdges<<endl;
            }
        }
        return cnt;
    }
};