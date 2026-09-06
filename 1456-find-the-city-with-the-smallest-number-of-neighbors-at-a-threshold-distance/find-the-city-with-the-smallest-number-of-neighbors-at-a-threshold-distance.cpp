class Solution {
public:
    void solve(int i, vector<vector<pair<int, int>>>& adj, vector<int>& dis, int& k){
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        pq.push({0, i});
        dis[i] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d > k){
                continue;
            }
            for(auto it : adj[node]){
                int v = it.first;
                int w = it.second;
                int newDis = d + w;
                if(newDis <= k && newDis < dis[v]){
                    dis[v] = newDis;
                    pq.push({newDis, v});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int ans = -1;
        int val = 1e9;
        for(int i =0; i<n; i++){
            vector<int> dis(n, 1e9);
            solve(i, adj, dis, distanceThreshold);
            int cnt = 0;
            for(int j =0; j<n; j++){
                if(dis[j] != 1e9){
                    cnt++;
                }
            }
            if(cnt <= val){
                ans = i;
                val = cnt;
            }
        }
        return ans;
    }
};