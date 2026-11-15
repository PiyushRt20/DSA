class Solution {
public:
    vector<vector<int>> adj;
    vector<int> op, score;

    long long dfs(int u) {
        if(adj[u].empty()) return score[u];

        long long sum = 0;
        long long mini = LLONG_MAX;

        for(auto v : adj[u]) {
            long long x = dfs(v);
            sum += x;
            mini = min(mini, x);
        }

        if(op[u] == 0) mini = min(mini, 0LL);

        return score[u] + sum - mini;
    }

    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();

        adj.resize(n);
        this->op = op;
        this->score = score;

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        return dfs(0);
    }
};