class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& vis, vector<int>& indegree){
        vis[node] = 1;
        // indegree[node]--;
        for(auto it : adj[node]){
            if(!vis[it]){
                indegree[it]--;
                dfs(it, adj, vis, indegree);
            }
            else{
                indegree[it]--;
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(auto it : invocations){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<int> vis(n, 0);
        dfs(k, adj, vis, indegree);
        vector<int> ans;
        bool flag = false;
        for(auto it : indegree){
            cout<<it<<" ";
        }
        for(int i =0; i<n; i++){
            if(vis[i] == 1 && indegree[i] > 0){
                flag = true;
                break;
            }
        }
        if(flag){
            for(int i=0; i<n; i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i =0; i<n; i++){
                if(!vis[i]){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};