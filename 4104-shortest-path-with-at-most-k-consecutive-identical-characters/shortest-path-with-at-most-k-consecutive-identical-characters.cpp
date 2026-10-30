class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<vector<int>> dist(n , vector<int>(k+1, 1e9));
        dist[0][1] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,1}});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int cnt = pq.top().second.second;
            pq.pop();
            for(auto it : adj[node]){
                int temp = cnt;
                if(labels[it.first] == labels[node]){
                    temp++;
                }else{
                    temp = 1;
                }
                if(temp <= k){
                    int newDis = dis + it.second;
                    if(dist[it.first][temp] > newDis){
                        dist[it.first][temp] = newDis;
                        pq.push({newDis, {it.first, temp}});
                    }
                }
                    
            }
        }
        int ans = 1e9;
        for(int i =1; i<=k; i++){
            ans = min(ans, dist[n-1][i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};