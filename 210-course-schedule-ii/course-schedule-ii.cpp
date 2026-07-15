class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        for(int i =0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == n){
            return ans;
        }
        return {};
    }
};