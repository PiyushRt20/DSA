class Solution {
public:
    int height = 1;
    void dfs(int node, int d, vector<int>&depth, vector<vector<int>>&tree){
        depth[node] = d;
        height = max(d, height);
        
        for(auto it : tree[node]){
            dfs(it, d+1, depth, tree);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> tree(n);
        vector<int>depth(n);
        for(int i=1; i<n; i++){
            tree[parent[i]].push_back(i);
        }
        dfs(0, 1, depth, tree);

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (height - depth[i] + 1);
        }
        return ans;
    }
};