class Solution {
public:
    int maxi = -1;

    void dfs(int node, vector<int>& edges, vector<int>& vis,
             vector<int>& pathVis, vector<int>& depth) {

        vis[node] = 1;
        pathVis[node] = 1;

        int next = edges[node];

        if (next != -1) {
            if (!vis[next]) {
                depth[next] = depth[node] + 1;
                dfs(next, edges, vis, pathVis, depth);
            }
            else if (pathVis[next]) {
                maxi = max(maxi, depth[node] - depth[next] + 1);
            }
        }

        pathVis[node] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> depth(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                depth[i] = 1;
                dfs(i, edges, vis, pathVis, depth);
            }
        }

        return maxi;
    }
};